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

#include "NumericSortFilterModel.h"

namespace Ramio {

NumericSortFilterModel::NumericSortFilterModel(QObject* parent)
	: QSortFilterProxyModel(parent)
{
}

Ramio::NumericSortFilterModel::~NumericSortFilterModel() = default;

QVariant NumericSortFilterModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Vertical && role == Qt::DisplayRole)
		return section+1;
	return QSortFilterProxyModel::headerData(section, orientation, role);
}

} // Ramio::
