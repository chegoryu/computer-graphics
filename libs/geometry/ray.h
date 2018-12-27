#pragma once

#include "point.h"


class TRay {
public:
    TRay(const TPoint& startPosition = TPoint(), const TPoint& direction = TPoint())
        : StartPosition_(startPosition)
        , Direction_(direction)
    {
    }

public:
    TPoint StartPosition_;
    TPoint Direction_;
};
