#pragma once

#include "point.h"


class TLight {
public:
    enum ELightType {
        AMBIENT
        , DIRECTION
        , POINT
    };

public:
    TLight(ELightType type, TDoubleType intensity, TPoint direction = TPoint(), TPoint position = TPoint())
        : Type_(type)
        , Intensity_(intensity)
        , Position_(position)
        , Direction_(direction)
    {
    }

    static TLight MakeAmbientLight(TDoubleType intensity);
    static TLight MakeDirectionLight(TDoubleType intensity, const TPoint& direction);
    static TLight MakePointLight(TDoubleType intensity, const TPoint& position);

public:
    ELightType Type_;
    TDoubleType Intensity_;
    TPoint Position_;
    TPoint Direction_;
};
