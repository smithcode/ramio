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

#include "Logger.h"

#define FILEAME QString(__FILE__).mid(QString(__FILE__).lastIndexOf("/") + 1)

// Просто лог
#define LOG(text) Ramio::Logger::instance().log(text)
#define LOG_T(text) Ramio::Logger::instance().log(Ramio::timeLogFormatStr() % " " % text)

// Лог для пользователя
#define ULOG(text) Ramio::Logger::instance().ulog(text)

// Уведомления
#define NLOG(title, text) Ramio::Logger::instance().nlog(title, text)

#define NLOG_CODE(title, text, code) Ramio::Logger::instance().nlog(title, text, code)

// Лог для пользователя (варнинги)
#define WLOG(text) Ramio::Logger::instance().wlog(text)

// Лог для пользователя (ошибки)
#define ELOG(text) Ramio::Logger::instance().elog(text)

// Лог для пользователя (ошибки)
#define EMLOG(module, text) Ramio::Logger::instance().emlog(module, text)

// Лог для пользователя (модули)
#define MLOG(module, text) Ramio::Logger::instance().mlog(module, text)


// Информация о события в программе
#define PLOG(text) Ramio::Logger::instance().plog(text, QStringLiteral("<") % __func__ % QStringLiteral("> "))

// Информация об отладке
#define DLOG(text) Ramio::Logger::instance().dlog(text, QStringLiteral("{") % __func__ % ":" % QString::number(__LINE__) % "} " )
#define DWLOG(text) Ramio::Logger::instance().dwlog(text, QStringLiteral("{") % __func__ % ":" % QString::number(__LINE__) % "} " )
#define DLOG_FULL(text) Ramio::Logger::instance().dlog(text, QStringLiteral("{") % FILEAME % ":" % __func__ % ":" % QString::number(__LINE__) % "} " )
#define DLOG_POINT DLOG_FULL("")

// Критическое сообщение
#define CLOG(text) Ramio::Logger::instance().clog(text, QStringLiteral("{") % FILEAME % ":" % __func__ % ":" % QString::number(__LINE__) % "} ")

// Прочее
#if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
	#define Qt_SkipEmptyParts Qt::SkipEmptyParts
#else
	#define Qt_SkipEmptyParts QString::SkipEmptyParts
#endif
