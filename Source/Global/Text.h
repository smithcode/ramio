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
#include <QStringBuilder>

extern const QLatin1String RAMIO_LIB_EXPORT txt_colorStartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_colorMiddleStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_colorEndStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_blueStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_redStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_yellowStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_orangeStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_darkMagentaStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_grayStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_greenStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_color_whiteStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_commentStartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_italicStartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_italicEndStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_boldStartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_boldEndStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header1StartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header1EndStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header2StartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header2EndStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header3StartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header3EndStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header4StartStr;
extern const QLatin1String RAMIO_LIB_EXPORT txt_header4EndStr;

#define TOTEXT(text) #text

#define COLORTEXT(text, color) (txt_colorStartStr % color % txt_colorMiddleStr % text % txt_colorEndStr)
#define BLUETEXT(text) COLORTEXT(text, txt_color_blueStr)
#define REDTEXT(text) COLORTEXT(text, txt_color_redStr)
#define YELLOWTEXT(text) COLORTEXT(text, txt_color_yellowStr)
#define ORANGETEXT(text) COLORTEXT(text, txt_color_orangeStr)
#define DARKMAGENTATEXT(text) COLORTEXT(text, txt_color_darkMagentaStr)
#define GRAYTEXT(text) COLORTEXT(text, txt_color_grayStr)
#define GREENTEXT(text) COLORTEXT(text, txt_color_greenStr)
#define WHITETEXT(text) COLORTEXT(text, txt_color_whiteStr)

#define CHCOLOR(color) QString("<span style=\"color:%1\">■</span>").arg(QColor(color).name(QColor::HexArgb))

#define COMMENT(msg) (txt_italicStartStr % msg % txt_italicEndStr)
#define BOLD(msg)  (txt_boldStartStr % msg % txt_boldEndStr)
#define BOLDNUM(n)  (txt_boldStartStr % QString::number(n) % txt_boldEndStr)
#define ITALIC(msg) (txt_italicStartStr % msg % txt_italicEndStr)

#define H1(text) (txt_header1StartStr % text % txt_header1EndStr)
#define H2(text) (txt_header2StartStr % text % txt_header2EndStr)
#define H3(text) (txt_header3StartStr % text % txt_header3EndStr)
#define H4(text) (txt_header4StartStr % text % txt_header4EndStr)

#define PRETTY_T_FORMAT "hh:mm:ss"
#define PRETTY_D_FORMAT "dd.MM.yyyy"
#define PRETTY_DT_FORMAT "dd.MM.yyyy hh:mm"
