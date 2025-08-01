/*
 * Copyright (C) 2016-2025 Vladimir Kuznetsov <smithcoder@yandex.ru> https://smithcoder.ru/
 *
 * This file is part of the Ramio, RAM object with Input-Output instructions.
 *
 * Ramio is free software; you can redistribute it and/or modify it under the terms of the
 * GNU Lesser General Public License as published by the Free Software Foundation;
 * either version 3 of the License, or (at your option) any later version.
 *
 * Ramio is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Ramio; see the file LICENSE. If not, see <http://www.gnu.org/licenses/>.
 */

#include "TableWidget.h"
#include <Models/MetaItemsModel.h>
#include <Models/MetaItemsSortFilterModel.h>
#include <Gui/Global.h>
#include <Gui/ModelFilterWidget.h>
#include <Sets/UISets.h>
// Qt5
#include <QtWidgets/QTableView>
#include <QtWidgets/QHeaderView>

namespace Ramio {

TableWidget::TableWidget(MetaItemsModel& model, QSortFilterProxyModel* fmodel, QWidget *parent)
	: QWidget(parent), model_(&model)
{
	UI_CREATE_VLAYOUT(layout)
	layout->addWidget(table_ = new QTableView());
	if (!fmodel)
		fmodel = new MetaItemsSortFilterModel(this);
	fmodel->setSourceModel(model_);
	table_->setModel(fmodel);

	layout->addWidget(modelFilterWidget_ = new ModelFilterWidget(*fmodel, this));
	QObject::connect(table_->selectionModel(), &QItemSelectionModel::currentRowChanged,
					 [this](const QModelIndex& current, const QModelIndex& previous){
		table_->scrollTo(current, QAbstractItemView::EnsureVisible);
		const auto* last = static_cast<Item*>(previous.data(Qt::UserRole).value<void*>());
		const auto* curr = static_cast<Item*>(current.data(Qt::UserRole).value<void*>());
		if (last != curr)
			emit selectedChanged(curr);
	});
	QObject::connect(table_, &QTableView::activated, [this](const QModelIndex& index){
		if (const auto* item = static_cast<Item*>(index.data(Qt::UserRole).value<void*>()))
			emit activated(*item);
	});
}

TableWidget::TableWidget(const AbstractListSet& set, const Meta::Description& meta, QWidget* parent)
	: TableWidget(*new MetaItemsModel(set, meta, parent), new MetaItemsSortFilterModel(parent), parent)
{
}

TableWidget::TableWidget(const AbstractMetaSet& set, QWidget* parent)
	: TableWidget(*set.aSet(), set.meta(), parent)
{
	Q_ASSERT(set.aSet());
}

void TableWidget::setColumnIndexes(const QList<quint8>& columns)
{
	model_->setColumnIndexes(columns);
}

void TableWidget::setColumns(const QStringList& names)
{
	model_->setColumns(names);
}

void TableWidget::setCheckable()
{
	model_->setCheckable();
}

Item* TableWidget::currentItem()
{
	return static_cast<Ramio::Item*>(table_->currentIndex().data(Qt::UserRole).value<void*>());
}

void TableWidget::selectItem(Item* item)
{
	if (!item)
		table_->selectRow(-1);
	else
		for(int i = 0; i < table_->model()->rowCount(); i++)
			if (table_->model()->index(i, 0).data(Qt::UserRole).value<void*>() == item)
			{
				table_->selectRow(i);
				return;
			}
}

void TableWidget::reload()
{
	model_->resetModel();
}

void TableWidget::loadSettings()
{
	PREPARE_TABLE(table_);
}

void TableWidget::saveSettings()
{
	SAVE_WIDGET(table_);
}

} // Ramio::
