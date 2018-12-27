#include "lights.h"

TLight MakeAmbientLight(TDoubleType intensity) {
    return TLight(TLight::ELightType::AMBIENT, intensity);
}

TLight MakeDirectionLight(TDoubleType intensity, TPoint direction) {
    return TLight(TLight::ELightType::DIRECTION, intensity, direction);
}

TLight MakePointLight(TDoubleType intensity, TPoint direction, TPoint position) {
    return TLight(TLight::ELightType::POINT, intensity, direction, position);
}
