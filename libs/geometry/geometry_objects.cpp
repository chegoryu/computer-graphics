#include "geometry_objects.h"


TPoint TGeometryPlane::GetNormalAtPoint(const TPoint& from, const TPoint& /* position */) const {
    TPoint normal = ((B_ - A_) * (C_ - A_)).GetNormalize();
    if (normal % (from - A_) > 0.0) {
        return normal;
    } else {
        return -normal;
    }
}

std::vector<TDoubleType> TGeometryPlane::IntersectRay(const TRay& ray) const {
    TPoint normal = GetNormalAtPoint(ray.StartPosition_, TPoint());
    if (normal % ray.Direction_ <= TPoint::EPSILON) {
        return std::vector<TDoubleType>();
    } else {
        std::vector<TDoubleType> answer;
        TDoubleType intersect = (normal % (A_ - ray.StartPosition_)) / (normal % ray.Direction_);
        if (intersect > -TPoint::EPSILON) {
            answer.push_back(intersect);
        }
        return answer;
    }
}

TPoint TGeometrySphere::GetNormalAtPoint(const TPoint& /* from */, const TPoint& position) const {
    return (position - Center_).GetNormalize();
}

std::vector<TDoubleType> TGeometrySphere::IntersectRay(const TRay& ray) const {
    TPoint direction = ray.StartPosition_ - Center_;

    TDoubleType a = ray.Direction_.GetSquare();
    TDoubleType b = 2.0 * (ray.Direction_ % direction);
    TDoubleType c = direction.GetSquare() - Radius_ * Radius_;
    TDoubleType d = b * b - 4.0 * a * c;

    if (d <= -TPoint::EPSILON) {
        return std::vector<TDoubleType>();
    } else {
        std::vector<TDoubleType> answer;
        TDoubleType intersect1 = (-b + sqrt(std::max(d, 0.0))) / (2.0 * a);
        TDoubleType intersect2 = (-b - sqrt(std::max(d, 0.0))) / (2.0 * a);

        if (intersect1 > -TPoint::EPSILON) {
            answer.push_back(intersect1);
        }
        if (intersect2 > -TPoint::EPSILON) {
            answer.push_back(intersect2);
        }

        return answer;
    }
}
