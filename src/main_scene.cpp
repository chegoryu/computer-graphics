#include "main_scene.h"

void TMainScene::InitWindow() {
    WindowWidthPosition_ = 150;
    WindowHeightPosition_ = 150;
    WindowWidthSize_ = 800;
    WindowHeightSize_ = 600;
    WindowName_ = "ComputerGraphics";
}

void TMainScene::InitScene() {
    CameraRay_ = TRay(TPoint(0.0, 1.0, -3.0), TPoint(0.0, 0.0, 1.0));

    Objects_.push_back(std::make_unique<TGeometrySphere>(500.0, 0.2, TColor(1.5, 0.0, 0.0), 1.0, TPoint(0.0, -1.0, 3.0)));
    Objects_.push_back(std::make_unique<TGeometrySphere>(500.0, 0.4, TColor(0.0, 0.0, 1.0), 1.0, TPoint(2.0, 0.0, 4.0)));
    Objects_.push_back(std::make_unique<TGeometrySphere>(10.0, 0.5, TColor(0.0, 1.2, 0.0), 1.4, TPoint(-2.3, 0.0, 4.0)));
    Objects_.push_back(std::make_unique<TGeometrySphere>(200.0, 0.95, TColor(0.0, 1.2, 0.0), 2.5, TPoint(0.0, 3, 7.0)));

    Objects_.push_back(std::make_unique<TGeometryPlane>(400.0, 0.2, TColor(0.5, 0.5, 0.0), TPoint(0.0, -1.0, 0.0), TPoint(1.0, -1.0, 1.0), TPoint(-1.0, -1.0, 1.0)));
    Objects_.push_back(std::make_unique<TGeometryPlane>(20.0, 0.05, TColor(0.5, 0.5, 0.0), TPoint(0.0, 20.0, 0.0), TPoint(1.0, 20.0, 1.0), TPoint(-1.0, 20.0, 1.0)));
    Objects_.push_back(std::make_unique<TGeometryPlane>(20.0, 0.05, TColor(0.5, 0.5, 0.0), TPoint(-20.0, 0.0, 0.0), TPoint(-20.0, -1.0, 1.0), TPoint(-20.0, 1.0, 1.0)));
    Objects_.push_back(std::make_unique<TGeometryPlane>(20.0, 0.05, TColor(0.5, 0.5, 0.0), TPoint(20.0, 0.0, 0.0), TPoint(20.0, -1.0, 1.0), TPoint(20.0, 1.0, 1.0)));
    Objects_.push_back(std::make_unique<TGeometryPlane>(20.0, 0.05, TColor(0.5, 0.5, 0.0), TPoint(0.0, 0.0, 20.0), TPoint(1.0, -1.0, 20.0), TPoint(-1.0, -1.0, 20.0)));
    Objects_.push_back(std::make_unique<TGeometryPlane>(20.0, 0.05, TColor(0.5, 0.5, 0.0), TPoint(0.0, 0.0, -20.0), TPoint(1.0, -1.0, -20.0), TPoint(-1.0, -1.0, -20.0)));

    Lights_.push_back(TLight::MakeAmbientLight(0.2));
    Lights_.push_back(TLight::MakeDirectionLight(0.3, TPoint(-1.0, -3.0, -1.0)));
    Lights_.push_back(TLight::MakePointLight(0.6, TPoint(4.0, 1.0, -1.0)));
}
