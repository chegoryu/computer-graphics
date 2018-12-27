#pragma once

#include "color.h"
#include "point.h"


class TGeometryObject {
public:
    TGeometryObject()
    {
    }



public:
    TDoubleType Specular_;
    TDoubleType Reflective_;
    TColor Color_;
};
