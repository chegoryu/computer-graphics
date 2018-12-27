#pragma once

#include "common.h"


class TColor {
public:
    TColor(TDoubleType r = 0.0, TDoubleType g = 0.0, TDoubleType b = 0.0)
        : R_(r)
        , G_(g)
        , B_(b)
    {
        FixColor();
    }

private:
    void FixColor();

public:
    TDoubleType R_;
    TDoubleType G_;
    TDoubleType B_;

private:
    const static TDoubleType MIN_COLOR;
    const static TDoubleType MAX_COLOR;
};

TColor operator+(const TColor& a, const TColor& b);
TColor operator-(const TColor& a, const TColor& b);
TColor operator*(const TColor& a, TDoubleType x);
TColor operator*(TDoubleType x, const TColor& a);
TColor operator/(const TColor& a, TDoubleType x);
