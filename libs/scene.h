#pragma once

class TScene {
public:
    TScene(int argc, char **argv) {
    }

    void Draw();

protected:
    virtual void InitWindow() = 0;
    virtual void PlaceObjects() = 0;
};
