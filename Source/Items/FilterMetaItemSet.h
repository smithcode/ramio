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

#pragma once

#include "FilterItemSet.h"
#include "AbstractMetaSet.h"

namespace Ramio {

template<typename STRUCTITEM>
class FilterMetaItemSet : public FilterItemSet<STRUCTITEM>, public AbstractMetaSet
{
public:
	FilterMetaItemSet(const AbstractListSet& originalSet, std::function<bool(const STRUCTITEM& t1)> filterFunction,
					  QObject* parent = Q_NULLPTR)
		: FilterItemSet<STRUCTITEM>(originalSet, filterFunction, parent),
		  AbstractMetaSet(reinterpret_cast<const QList<const StructItem<MetaItemData>*>&>(FilterItemSet<STRUCTITEM>::items())) {}

	FilterMetaItemSet(const AbstractMetaSet& originalSet, std::function<bool(const STRUCTITEM& t1)> filterFunction,
					  QObject* parent = Q_NULLPTR)
		: FilterItemSet<STRUCTITEM>(*originalSet.aSet(), filterFunction, parent),
		  AbstractMetaSet(reinterpret_cast<const QList<const StructItem<MetaItemData>*>&>(FilterItemSet<STRUCTITEM>::items()), originalSet.meta(), originalSet.relations()) {}

	~FilterMetaItemSet() Q_DECL_OVERRIDE {this->clear();}

	StructItem<MetaItemData>* createMetaItem() const Q_DECL_OVERRIDE {return Q_NULLPTR;}
	StructItem<MetaItemData>* createMetaItem(const MetaItemData& data) const Q_DECL_OVERRIDE {Q_UNUSED(data); return Q_NULLPTR;}
	MetaItemData* createMetaItemData() const Q_DECL_OVERRIDE  {return Q_NULLPTR;}
	void insertMetaItem(StructItem<MetaItemData>* item) Q_DECL_OVERRIDE {Q_UNUSED(item);}
	AbstractListSet* aSet() Q_DECL_OVERRIDE {return this;}
	AbstractMetaSet* mSet() Q_DECL_OVERRIDE {return this;}
	AbstractMetaSet* createTemporaryMetaSet(QObject* parent = Q_NULLPTR) const Q_DECL_OVERRIDE {Q_UNUSED(parent); return Q_NULLPTR;}
};

} // Ramio::

#include "FilterMetaItemSet.inl"
