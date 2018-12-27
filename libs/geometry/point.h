#pragma once

#include "common.h"


class TPoint {
public:
    TPoint(TDoubleType x = 0.0, TDoubleType y = 0.0, TDoubleType z = 0.0)
        : X_(x)
        , Y_(y)
        , Z_(z)
    {
    }

    TDoubleType GetSquare() const;
    TDoubleType GetLen() const;
    TPoint GetNormalize() const;
    TPoint GetReflective(const TPoint& normal) const;

public:
    TDoubleType X_;
    TDoubleType Y_;
    TDoubleType Z_;

public:
    static const TDoubleType EPSILON;
};

TPoint operator+(const TPoint& a, const TPoint& b);
TPoint operator-(const TPoint& a, const TPoint& b);
TPoint operator-(const TPoint& a);
TPoint operator*(const TPoint& a, TDoubleType x);
TPoint operator*(TDoubleType x, const TPoint& a);
TPoint operator/(const TPoint& a, TDoubleType x);
TPoint operator*(const TPoint& a, const TPoint& b);
TDoubleType operator%(const TPoint& a, const TPoint& b);

bool operator==(const TPoint& a, const TPoint& b);
bool operator!=(const TPoint& a, const TPoint& b);
