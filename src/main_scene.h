#pragma once
#include "scene/scene.h"

class TMainScene: public TScene {
public:
    TMainScene(int argc, char** argv)
        : TScene(argc, argv)
    {
    }

private:
    virtual void InitWindow() override final;
    virtual void PlaceObjects() override final;
};
