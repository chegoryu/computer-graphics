#pragma once

#include "color.h"
#include "point.h"
#include "ray.h"

#include <vector>

class TGeometryObject {
public:
    TGeometryObject(TDoubleType specular, TDoubleType reflective, TColor color)
        : Specular_(specular)
        , Reflective_(reflective)
        , Color_(color)
    {
    }

    virtual ~TGeometryObject() = default;

    virtual TPoint GetNormalAtPoint(const TPoint& from, const TPoint& position) const = 0;
    virtual std::vector<TDoubleType> IntersectRay(const TRay& ray) const = 0;

public:
    TDoubleType Specular_;
    TDoubleType Reflective_;
    TColor Color_;
};

class TGeometryPlane: public TGeometryObject {
public:
    TGeometryPlane(
        TDoubleType specular
        , TDoubleType reflective
        , TColor color
        , const TPoint& a
        , const TPoint& b
        , const TPoint& c
     )
        : TGeometryObject(specular, reflective, color)
        , A_(a)
        , B_(b)
        , C_(c)
    {
    }

    virtual TPoint GetNormalAtPoint(const TPoint& from, const TPoint& position) const override final;
    virtual std::vector<TDoubleType> IntersectRay(const TRay& ray) const override final;

private:
    TPoint A_;
    TPoint B_;
    TPoint C_;
};

class TGeometrySphere: public TGeometryObject {
public:
    TGeometrySphere(
        TDoubleType specular
        , TDoubleType reflective
        , TColor color
        , TDoubleType radius
        , const TPoint& center
    )
        : TGeometryObject(specular, reflective, color)
        , Radius_(radius)
        , Center_(center)
    {
    }

    virtual TPoint GetNormalAtPoint(const TPoint& from, const TPoint& position) const override final;
    virtual std::vector<TDoubleType> IntersectRay(const TRay& ray) const override final;

private:
    TDoubleType Radius_;
    TPoint Center_;
};
