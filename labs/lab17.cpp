#include "lab17.h"
#include <cmath>
#include <iostream>

void Lab17::compute_concentrations(double t_max, double dt,
                                   std::vector<double>& times,
                                   std::vector<double>& concentrations_A,
                                   std::vector<double>& concentrations_B,
                                   std::vector<double>& concentrations_C,
                                   std::vector<double>& optical_densities) {
    std::cout << "Lab17::compute_concentrations(...) entered" << std::endl;
    double A = 1.0; // Начальная концентрация A
    double B = 0.0; // Начальная концентрация B
    double C = 0.0; // Начальная концентрация C

    for (double t = 0; t <= t_max; t += dt) {
        // Модель изменения концентраций во времени
        double dA = -k1 * A * dt;
        double dB = (k1 * A - k2 * B) * dt;
        double dC = k2 * B * dt;

        A += dA;
        B += dB;
        C += dC;

        // Заполнение векторов для графиков
        times.push_back(t);
        concentrations_A.push_back(A);
        concentrations_B.push_back(B);
        concentrations_C.push_back(C);

        // Оптическая плотность
        double optical_density = eps_A * A + eps_B * B + eps_C * C;
        optical_densities.push_back(optical_density);
    }
}
