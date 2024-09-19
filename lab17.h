#ifndef LAB17_H
#define LAB17_H

#include <vector>

/*
Визуализация кривых зависимости оптической плотности
Оптическая плотность смеси зависит от коэффициентов светопоглощения 
реагентов. Для реакции A→B→C можно предположить следующие соотношения между 
молярными коэффициентами светопоглощения (εA,εB, εC ) и концентрациями
 реагентов:
 -Оптическая плотность 𝐷(𝑡) реакционной смеси:
 D(t)=εA[A](t)+εB[B](t)+εC[C](t)

 Используем метод численного интегрирования для 
 моделирования изменения концентраций [A](t),[B](t),[C](t) во времени.
*/

class Lab17 {
private:
    double k1, k2; // Константы скорости для реакций A -> B -> C
    double eps_A, eps_B, eps_C; // Молярные коэффициенты светопоглощения

public:
    Lab17(double k1_val, double k2_val, double eps_A_val, double eps_B_val, double eps_C_val)
        : k1(k1_val), k2(k2_val), eps_A(eps_A_val), eps_B(eps_B_val), eps_C(eps_C_val) {}

    void compute_concentrations(double t_max, double dt,
                                std::vector<double>& times,
                                std::vector<double>& concentrations_A,
                                std::vector<double>& concentrations_B,
                                std::vector<double>& concentrations_C,
                                std::vector<double>& optical_densities);
};

#endif
