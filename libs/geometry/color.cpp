#include "color.h"

#include <algorithm>


const TDoubleType TColor::MIN_COLOR = 0.0;
const TDoubleType TColor::MAX_COLOR = 255.0;

void TColor::FixColor() {
    R_ = std::max(std::min(TColor::MAX_COLOR, R_), TColor::MIN_COLOR);
    G_ = std::max(std::min(TColor::MAX_COLOR, G_), TColor::MIN_COLOR);
    B_ = std::max(std::min(TColor::MAX_COLOR, B_), TColor::MIN_COLOR);
}

TColor operator+(const TColor& a, const TColor& b) {
    return TColor(a.R_ + b.R_, a.G_ + b.G_, a.B_ + b.B_);
}

TColor operator-(const TColor& a, const TColor& b) {
    return TColor(a.R_ - b.R_, a.G_ - b.G_, a.B_ - b.B_);
}

TColor operator-(const TColor& a) {
    return TColor(-a.R_, -a.G_, -a.B_);
}

TColor operator*(const TColor& a, TDoubleType x) {
    return TColor(a.R_ * x, a.G_ * x, a.B_ * x);
}

TColor operator*(TDoubleType x, const TColor& a) {
    return TColor(a.R_ * x, a.G_ * x, a.B_ * x);
}

TColor operator/(const TColor& a, TDoubleType x) {
    return TColor(a.R_ / x, a.G_ / x, a.B_ / x);
}
