#include "lights.h"

TLight TLight::MakeAmbientLight(TDoubleType intensity) {
    return TLight(TLight::ELightType::AMBIENT, intensity);
}

TLight TLight::MakeDirectionLight(TDoubleType intensity, const TPoint& direction) {
    return TLight(TLight::ELightType::DIRECTION, intensity, direction, TPoint());
}

TLight TLight::MakePointLight(TDoubleType intensity, const TPoint& position) {
    return TLight(TLight::ELightType::POINT, intensity, TPoint(), position);
}
