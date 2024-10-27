#include "lab12.h"
#include <cmath>
#include <iostream>

Lab12::Lab12(double conversion_time, double max_concentration_time) {
    std::cout << "Lab12::Lab12(...) entered" << std::endl;
    k1 = log(0.2) / conversion_time; // 80% за 72.5 мин
    k2 = log(2) / max_concentration_time; // максимум B за 55.5 мин
}

void Lab12::get_rates(double& k1_out, double& k2_out) {
    std::cout << "Lab12::get_rates(...) entered" << std::endl;
    k1_out = k1;
    k2_out = k2;
}
