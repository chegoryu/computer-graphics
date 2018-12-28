#include "scene.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


TScene* TScene::MainScene = nullptr;
const size_t TScene::START_DEPTH = 5;

void TScene::DrawAll() {
    InitWindow();
    InitScene();
    InitGlut();
}

void TScene::DrawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1.3);

    for (ssize_t i = -WindowWidthSize_ / 2; i <= WindowWidthSize_ / 2; ++i) {
        for (ssize_t j = -WindowHeightSize_ / 2; j <= WindowHeightSize_ / 2; ++j) {
            TDoubleType curX = (TDoubleType)(i + 1) / WindowWidthSize_;;
            TDoubleType curY = (TDoubleType)(j + 1) / WindowHeightSize_;
            if (CameraRay_.Direction_.Z_ < 0) {
                curX = -curX;
                curY = -curY;
            }

            TPoint shift = TPoint(curX, CameraRay_.Direction_.Z_ / CameraRay_.Direction_.GetLen() * curY, -CameraRay_.Direction_.Y_ / CameraRay_.Direction_.GetLen() *curY);
            TRay curRay = TRay(CameraRay_.StartPosition_, CameraRay_.Direction_ + shift);
            TColor curColor = TraceRay(curRay, TScene::START_DEPTH, TPoint::EPSILON, TPoint::INF);

            glColor3f(curColor.R_, curColor.G_, curColor.B_);
            glBegin(GL_POINTS);
            glVertex2i(i, j);
            glEnd();
        }
    }

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
    glOrtho(-WindowWidthSize_ / 2.0, WindowWidthSize_ / 2.0, -WindowHeightSize_ / 2.0, WindowHeightSize_ / 2.0, -300, 300);
    glutDisplayFunc(GlupDrawScene);
    glutMainLoop();
}

void TScene::GlupDrawScene() {
    MainScene->DrawScene();
}

TColor TScene::TraceRay(const TRay& ray, size_t availableDepth, TDoubleType minimumPosition, TDoubleType maximalPosition) {
    if (availableDepth == 0) {
        return TColor();
    }

    TScene::TObjectIntersection nearestObject = NearestObject(ray, minimumPosition, maximalPosition);
    if (nearestObject.Index_ == -1) {
        return TColor();
    } else {
        TPoint position = ray.GetAtPosition(nearestObject.Position_);
        TPoint normal = Objects_[nearestObject.Index_]->GetNormalAtPoint(ray.StartPosition_, position).GetNormalize();

        TColor curColor = Objects_[nearestObject.Index_]->Color_ * GetLightIntensity(position, normal, -ray.Direction_, Objects_[nearestObject.Index_]->Specular_);

        if (Objects_[nearestObject.Index_]->Reflective_ > TPoint::EPSILON) {
            TColor reflectiveColor = TraceRay(TRay(position, (-ray.Direction_).GetReflective(normal)), availableDepth - 1, TPoint::EPSILON, TPoint::INF / 2.0);
            return reflectiveColor * Objects_[nearestObject.Index_]->Reflective_ + curColor * (1.0 - Objects_[nearestObject.Index_]->Reflective_);
        } else {
            return curColor;
        }
    }
}

TDoubleType TScene::GetLightIntensity(const TPoint& position, const TPoint& normal, const TPoint view, TDoubleType specular) {
    TDoubleType intensity = 0.0;
    for (size_t i = 0; i < Lights_.size(); ++i) {
        if (Lights_[i].Type_ == TLight::ELightType::AMBIENT) {
            intensity += Lights_[i].Intensity_;
        } else {
            TPoint shift = Lights_[i].Type_ == TLight::ELightType::DIRECTION ? Lights_[i].Direction_ * TPoint::INF / 10.0 : Lights_[i].Position_ - position;

            if (NearestObject(TRay(position, shift), TPoint::EPSILON * 10, 1.0).Index_ == -1) {
                TDoubleType scProd = normal % shift;
                if (scProd > 0.0) {
                    intensity += Lights_[i].Intensity_ * scProd / normal.GetLen() / shift.GetLen();
                }

                if (specular > 0.0) {
                    TDoubleType reflectiveView = shift.GetReflective(normal) % view;
                    if (reflectiveView > 0.0) {
                        intensity += Lights_[i].Intensity_ * pow(reflectiveView / shift.GetReflective(normal).GetLen() / view.GetLen(), specular);
                    }
                }
            }
        }
    }

    return intensity;
}

TScene::TObjectIntersection TScene::NearestObject(const TRay& ray, TDoubleType minimumPosition, TDoubleType maximalPosition) {
    TScene::TObjectIntersection nearestObject;
    for (size_t i = 0; i < Objects_.size(); ++i) {
        std::vector<TDoubleType> positions = Objects_[i]->IntersectRay(ray);
        for (size_t j = 0; j < positions.size(); ++j) {
            if (minimumPosition <= positions[j] && positions[j] <= maximalPosition && TScene::TObjectIntersection(i, positions[j]) < nearestObject) {
                nearestObject = TScene::TObjectIntersection(i, positions[j]);
            }
        }
    }

    return nearestObject;
}
