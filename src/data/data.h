#pragma once

#include "data_types.h"

#include "runtime.h"
#include "storage.h"
#include "applier.h"

class Data
{
public:
    Runtime runtime;

    Storage storage{runtime};
    Applier applier{runtime};
};