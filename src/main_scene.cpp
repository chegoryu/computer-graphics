#include "main_scene.h"

void TMainScene::InitWindow() {
    WindowWidthPosition_ = 150;
    WindowHeightPosition_ = 150;
    WindowWidthSize_ = 800;
    WindowHeightSize_ = 600;
    WindowName_ = "ComputerGraphics";
}

void TMainScene::PlaceObjects() {
    CameraRay_ = TRay(TPoint(0.0, 0.0, -1.0), TPoint(0.0, 0.0, 1.0));

    Objects_.push_back(std::make_unique<TGeometrySphere>(500.0, 0.0, TColor(255.0, 0.0, 0.0), 1.0, TPoint(0.0, -1.0, 3.0)));
    Objects_.push_back(std::make_unique<TGeometrySphere>(500.0, 0.0, TColor(0.0, 0.0, 255.0), 1.0, TPoint(2.0, 0.0, 4.0)));
    Objects_.push_back(std::make_unique<TGeometrySphere>(10.0, 0.0, TColor(0.0, 255.0, 0.0), 1.0, TPoint(-2.0, 0.0, 4.0)));
}
