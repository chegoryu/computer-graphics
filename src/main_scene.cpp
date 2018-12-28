#include "main_scene.h"

void TMainScene::InitWindow() {
    WindowWidthPosition_ = 150;
    WindowHeightPosition_ = 150;
    WindowWidthSize_ = 800;
    WindowHeightSize_ = 600;
    WindowName_ = "ComputerGraphics";
}

void TMainScene::InitScene() {
    CameraRay_ = TRay(TPoint(0.0, 0.0, -1.0), TPoint(0.0, 0.0, 1.0));

    Objects_.push_back(std::make_unique<TGeometrySphere>(500.0, 0.2, TColor(1.5, 0.0, 0.0), 1.0, TPoint(0.0, -1.0, 3.0)));
    Objects_.push_back(std::make_unique<TGeometrySphere>(500.0, 0.4, TColor(0.0, 0.0, 1.0), 1.0, TPoint(2.0, 0.0, 4.0)));
    Objects_.push_back(std::make_unique<TGeometrySphere>(10.0, 0.5, TColor(0.0, 1.2, 0.0), 1.0, TPoint(-2.0, 0.0, 4.0)));
    //Objects_.push_back(std::make_unique<TGeometrySphere>(5000.0, 0.1, TColor(1.0, 1.0, 0.0), 5000.0, TPoint(0.0, -5001, 0.0)));

    Objects_.push_back(std::make_unique<TGeometryPlane>(30.0, 0.0, TColor(0.0, 1.0, 1.0), TPoint(0.0, -1.0, 0.0), TPoint(1.0, -1.0, 1.0), TPoint(1.0, -1.0, -1.0)));

    Lights_.push_back(TLight::MakeAmbientLight(0.2));
    Lights_.push_back(TLight::MakeDirectionLight(0.2, TPoint(1.0, 4.0, 4.0)));
    Lights_.push_back(TLight::MakePointLight(0.6, TPoint(2.0, 1.0, 0.0)));
}
