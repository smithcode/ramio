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

#include <ramio.h>
#include <QtCore/QString>
class QDebug;

#define RD_UNKNOWN_ERROR -2
#define RD_UNSET_ERROR -1
#define RD_NO_ERROR 0
#define RD_ERROR 1
#define RD_OK 2
#define RD_NOT_CURENT_ACTION_ERROR 3
#define RD_NOT_CRITICAL_ERROR 4
#define RD_WARNING 5
#define RD_ERROR_WITH_DESC 6
#define RD_AUTHORIZATION_ERROR 7
#define RD_SESSION_ERROR 8
#define RD_PROTOCOL_ERROR 9
#define RD_ACTION_ERROR 10
#define RD_FORMAT_ERROR 11
#define RD_DATA_ERROR 12
#define RD_LOGIC_ERROR 13
#define RD_PROGRAMM_ERROR 14
#define RD_NOT_SUPPORT 15
#define RD_IO_ERROR 16
#define RD_NETWORK_ERROR 17
#define RD_DEVICE_ERROR 18
#define RD_DATABASE_ERROR 19
#define RD_NOT_FOUND 20
#define RD_ALLOC_ERROR 21


namespace Ramio {

/**
 * @brief The ResDesc struct.
 * Струтура с кодом ошибки и описания.
 */
struct RAMIO_LIB_EXPORT ResDesc
{
	int res = RD_NO_ERROR;
	QString desc;

	ResDesc() = default;
	ResDesc(int p_res) : res(p_res) {}
	ResDesc(int p_res, QString p_desc) : res(p_res), desc(std::move(p_desc)) {}

	inline bool noError() const { return !res || res == RD_OK;}
	inline bool noCriticalError() const { return (noError() || res == RD_NOT_CRITICAL_ERROR || res == RD_WARNING);}
	inline bool hasError() const {return !noCriticalError();}

	static bool noError(int code) { return !code || code == RD_OK;}

	void setResDesc(int v_res, QString v_desc = emptyString) {res = v_res; desc = std::move(v_desc);}
	void setResDesc(const ResDesc&& rd) {res = rd.res; desc = std::move(rd.desc);}
};

RAMIO_LIB_EXPORT QDebug operator << (QDebug dbg, const ResDesc& rd);

} // Ramio::
