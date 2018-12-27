#include "ray.h"


TPoint TRay::GetAtPosition(TDoubleType position) const {
    return StartPosition_ + Direction_ * position;
}
