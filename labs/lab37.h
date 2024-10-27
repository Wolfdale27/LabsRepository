#ifndef LAB37_H
#define LAB37_H

#include <vector>

class Lab37 {
private:
    double q;      // скорость образования ионов (катионы + анионы)
    double alpha;  // коэффициент рекомбинации
    double n0;     // начальное количество ионов
public:
    Lab37(double q_val, double alpha_val, double n0_val)
        : q(q_val), alpha(alpha_val), n0(n0_val) {}

    // Метод для решения уравнения с использованием метода Эйлера
    void simulate_ionization(double time, double dt, std::vector<double>& times, std::vector<double>& ion_counts);
};

#endif
