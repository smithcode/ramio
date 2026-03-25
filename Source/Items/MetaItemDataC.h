#pragma once

#include "MetaItemData.h"

#define RMETA_DATA_FIELD_C(name, type, prettyname) \
	RMETA_DATA_PROPERTY(name, type, cameCaseFirstChar(#name), prettyname, Field, QString())

#define RMETA_DATA_FKEY_ID_C(name, prettyname) \
	RMETA_DATA_PROPERTY(name, PKey, cameCaseFirstChar(#name), prettyname, FKey, "id")
