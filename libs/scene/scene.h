#pragma once

#include "geometry/geometry_objects.h"
#include "geometry/lights.h"

#include <memory>
#include <unistd.h>
#include <string>
#include <vector>


class TScene {
private:
    struct TObjectIntersection {
        TObjectIntersection(ssize_t index = -1, TDoubleType position = TPoint::INF)
            : Index_(index)
            , Position_(position)
        {
        }

        ssize_t Index_;
        TDoubleType Position_;

        bool operator<(const TObjectIntersection& other) {
            return Position_ < other.Position_;
        }
    };

public:
    TScene(int argc, char** argv)
        : Argc_(argc)
        , Argv_(argv)
        , WindowWidthPosition_(0)
        , WindowHeightPosition_(0)
        , WindowWidthSize_(0)
        , WindowHeightSize_(0)
        , WindowName_("")
        , CameraRay_()
        , Objects_()
    {
    }

    virtual ~TScene() = default;

    void DrawAll();

protected:
    virtual void InitWindow() = 0;
    virtual void InitScene() = 0;

private:
    void InitGlut();
    void DrawScene();
    static void GlupDrawScene();

    TColor TraceRay(const TRay& ray, size_t depth, TDoubleType minimumPosition, TDoubleType maximalPosition);
    TDoubleType GetLightIntensity(const TPoint& position, const TPoint& normal, const TPoint view, TDoubleType specular);
    TObjectIntersection NearestObject(const TRay& ray, TDoubleType minimumPosition, TDoubleType maximalPosition);

protected:
    int Argc_;
    char** Argv_;
    ssize_t WindowWidthPosition_;
    ssize_t WindowHeightPosition_;
    ssize_t WindowWidthSize_;
    ssize_t WindowHeightSize_;
    std::string WindowName_;

    TRay CameraRay_;
    std::vector<std::unique_ptr<TGeometryObject>> Objects_;
    std::vector<TLight> Lights_;
private:
    static const size_t START_DEPTH;

    static TScene* MainScene;
};
