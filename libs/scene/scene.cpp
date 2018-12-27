#include "scene.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


TScene* TScene::MainScene = nullptr;

void TScene::DrawAll() {
    InitWindow();
    InitGlut();
}

void TScene::DrawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.0);
    glutSwapBuffers();
}

void TScene::InitGlut() {
    glutInit(&Argc_, Argv_);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(WindowWidthPosition_, WindowHeightPosition_);
    glutInitWindowSize(WindowWidthSize_, WindowHeightSize_);
    glutCreateWindow(WindowName_.c_str());
    MainScene = this;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WindowWidthSize_ / 2.0, WindowWidthSize_ / 2.0, -WindowHeightSize_ / 2.0, WindowHeightSize_ / 2.0, -100, 100);
    glutDisplayFunc(GlupDrawScene);
    glutMainLoop();
}

void TScene::GlupDrawScene() {
    MainScene->DrawScene();
}
