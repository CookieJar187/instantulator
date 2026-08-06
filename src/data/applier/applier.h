#pragma once

#include "data_types.h"
#include "runtime.h"

class Applier
{
public:
    Applier(Runtime &runtime);

    void applySettings();

private:
    Runtime *runtime = nullptr;

};