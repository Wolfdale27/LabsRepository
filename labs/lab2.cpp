#include "lab2.h"
#include <cmath>
#include <iostream>

void Lab2::compute(double t, double& A, double& B, double& C) {
    std::cout << "Lab2::compute(" << t << ' ' << A << ' '<<  C << ") entered" << std::endl;
    A = A0 * exp(-k * t);
    B = B0 * exp(-k * t);
    C = C + (A0 - A); // просто пример зависимости, можно уточнить
}
