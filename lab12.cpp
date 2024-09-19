#include "lab12.h"
#include <cmath>

Lab12::Lab12(double conversion_time, double max_concentration_time) {
    k1 = log(0.2) / conversion_time; // 80% за 72.5 мин
    k2 = log(2) / max_concentration_time; // максимум B за 55.5 мин
}

void Lab12::get_rates(double& k1_out, double& k2_out) {
    k1_out = k1;
    k2_out = k2;
}
