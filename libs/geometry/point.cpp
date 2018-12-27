#include "point.h"

const TDoubleType TPoint::EPSILON = 1e-3;
const TDoubleType TPoint::INF = 1e+9;

TDoubleType TPoint::GetSquare() const {
    return *this % *this;
}

TDoubleType TPoint::GetLen() const {
    return sqrt(GetSquare());
}

TPoint TPoint::GetNormalize() const {
    return *this / GetLen();
}

TPoint TPoint::GetReflective(const TPoint& normal) const {
    return 2.0 * (*this % normal) * normal - *this;
}

TPoint operator+(const TPoint& a, const TPoint& b) {
    return TPoint(a.X_ + b.X_, a.Y_ + b.Y_, a.Z_ + b.Z_);
}

TPoint operator-(const TPoint& a, const TPoint& b) {
    return TPoint(a.X_ - b.X_, a.Y_ - b.Y_, a.Z_ - b.Z_);
}

TPoint operator-(const TPoint& a) {
    return TPoint(-a.X_, -a.Y_, -a.Z_);
}

TPoint operator*(const TPoint& a, TDoubleType x) {
    return TPoint(a.X_ * x, a.Y_ * x, a.Z_ * x);
}

TPoint operator*(TDoubleType x, const TPoint& a) {
    return TPoint(a.X_ * x, a.Y_ * x, a.Z_ * x);
}

TPoint operator/(const TPoint& a, TDoubleType x) {
    return TPoint(a.X_ / x, a.Y_ / x, a.Z_ / x);
}

TPoint operator*(const TPoint& a, const TPoint& b) {
    return TPoint(a.Y_ * b.Z_ - a.Z_ * b.Y_, -a.X_ * b.Z_ + a.Z_ * b.X_, a.X_ * b.Y_ - a.Y_ * b.X_);
}

TDoubleType operator%(const TPoint& a, const TPoint& b) {
    return a.X_ * b.X_ + a.Y_ * b.Y_ + a.Z_ * b.Z_;
}

bool operator==(const TPoint& a, const TPoint& b) {
    return CompareWithEpsilon((a - b).GetLen(), 0.0, TPoint::EPSILON);
}

bool operator!=(const TPoint& a, const TPoint& b) {
    return !CompareWithEpsilon((a - b).GetLen(), 0.0, TPoint::EPSILON);
}
