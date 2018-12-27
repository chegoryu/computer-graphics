#include "common.h"

bool CompareWithEpsilon(TDoubleType a, TDoubleType b, TDoubleType epsilon) {
    return abs(a - b) < epsilon;
}
