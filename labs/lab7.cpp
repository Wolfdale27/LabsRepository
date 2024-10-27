#include "lab7.h"
#include <cmath>
#include <iostream>

double Lab7::compute_decay_time(double half_life, double target_fraction) {
    std::cout << "Lab7::compute_decay_time(" << half_life << ' ' <<  target_fraction << ") entered" << std::endl;
    double k = log(2) / half_life; // Константа скорости
    return log(1.0 / target_fraction) / k;
}
