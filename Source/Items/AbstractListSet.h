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

#include "ItemObserver.h"

namespace Ramio {

class AbstractMetaSet;

class RAMIO_LIB_EXPORT AbstractListSet : public ItemObserver
{
	Q_OBJECT
	Q_DISABLE_COPY(AbstractListSet)
public:
	AbstractListSet(QList<Item*>& items, QObject* parent = Q_NULLPTR);
	~AbstractListSet() Q_DECL_OVERRIDE;

	virtual Item* createItem() const = 0;
	virtual Item* createItem(const ItemData& data) const = 0;
	virtual Item* createItem(ItemData&& data) const = 0;
	virtual AbstractListSet* createTemporaryItemSet(QObject* parent = Q_NULLPTR) const = 0;

	void insertItem(Item& item) {ItemObserver::addItem(item);}
	void removeItem(const Item& item) {ItemObserver::removeItem(item);}

	bool contains(const Item& item) const Q_DECL_OVERRIDE { return items_.contains(const_cast<Item*>(&item)); }
	int count() const Q_DECL_OVERRIDE { return items_.count(); }
	bool isEmpty() const Q_DECL_NOTHROW Q_DECL_OVERRIDE { return items_.isEmpty(); }
	bool notEmpty() const Q_DECL_NOTHROW Q_DECL_OVERRIDE { return !items_.isEmpty(); }
	void clear() Q_DECL_OVERRIDE;

	const QList<Item*>& items() { return items_; }
	const QList<const Item*>& items() const { return reinterpret_cast<const QList<const Item*>&>
				(const_cast<AbstractListSet*>(this)->items());}

	virtual Item* itemById(RMPKey id);
	const Item* itemById(RMPKey id) const {return const_cast<AbstractListSet*>(this)->itemById(id);}

	virtual AbstractMetaSet* mSet() {return Q_NULLPTR;}
	const AbstractMetaSet* mSet() const {return const_cast<AbstractListSet*>(this)->mSet();}

protected:
	void doOnItemAdding(Item& item) Q_DECL_OVERRIDE;
	void doOnItemChanging(Item& item) Q_DECL_OVERRIDE;
	void doOnItemChanged(Item& item) Q_DECL_OVERRIDE;
	void doOnItemRemoving(Item& item) Q_DECL_OVERRIDE;

private:
	QList<Item*>& items_;
};

} // Ramio::
