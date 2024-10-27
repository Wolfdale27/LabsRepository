#include "lab37.h"

void Lab37::simulate_ionization(double time, double dt, std::vector<double>& times, std::vector<double>& ion_counts) {
    double n = n0;  // начальное количество ионов
    for (double t = 0; t <= time; t += dt) {
        times.push_back(t);
        ion_counts.push_back(n);

        // Метод Эйлера: n(t+dt) = n(t) + dt * (q - alpha * n(t)^2)
        double dn_dt = q - alpha * n * n;
        n += dn_dt * dt;
    }
}
