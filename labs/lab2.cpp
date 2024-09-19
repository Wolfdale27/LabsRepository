#include "lab2.h"
#include <cmath>

void Lab2::compute(double t, double& A, double& B, double& C) {
    A = A0 * exp(-k * t);
    B = B0 * exp(-k * t);
    C = C + (A0 - A); // просто пример зависимости, можно уточнить
}
