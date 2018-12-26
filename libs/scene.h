#pragma once

#include <memory>
#include <string>
#include <vector>


class TScene {
public:
    TScene(int argc, char** argv)
        : Argc_(argc)
        , Argv_(argv)
        , WindowWidthPosition_(0)
        , WindowHeightPosition_(0)
        , WindowWidthSize_(0)
        , WindowHeightSize_(0)
        , WindowName_("")
    {
    }

    void DrawAll();

protected:
    virtual void InitWindow() = 0;
    virtual void PlaceObjects() = 0;

private:
    void InitGlut();
    void DrawScene();
    static void GlupDrawScene();

protected:
    int Argc_;
    char** Argv_;
    size_t WindowWidthPosition_;
    size_t WindowHeightPosition_;
    size_t WindowWidthSize_;
    size_t WindowHeightSize_;
    std::string WindowName_;

private:
    static std::shared_ptr<TScene> MainScene;
};
