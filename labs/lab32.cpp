
#include "lab32.h"

// Реализация метода моделирования реакции
void Lab32::simulate_reaction(double time, double dt, 
                              std::vector<double>& times, 
                              std::vector<double>& SiH2Cl2_conc,
                              std::vector<double>& SiHCl_conc,
                              std::vector<double>& HCl_conc,
                              std::vector<double>& SiCl2_conc) {
    
    // Начальные концентрации
    double SiH2Cl2 = 1.0; // Предполагаем, что начальная концентрация SiH2Cl2 равна 1.0
    double SiHCl = 0.0;
    double HCl = 0.0;
    double SiCl2 = 0.0;
    
    for (double t = 0; t <= time; t += dt) {
        times.push_back(t);
        SiH2Cl2_conc.push_back(SiH2Cl2);
        SiHCl_conc.push_back(SiHCl);
        HCl_conc.push_back(HCl);
        SiCl2_conc.push_back(SiCl2);

        // Дифференциальные уравнения реакции (с использованием метода Эйлера)
        double dSiH2Cl2_dt = -k1 * SiH2Cl2 + k_1 * SiHCl * HCl;
        double dSiHCl_dt = k1 * SiH2Cl2 - k_1 * SiHCl * HCl - k5 * SiHCl + k_5 * SiCl2;
        double dHCl_dt = k1 * SiH2Cl2 - k_1 * SiHCl * HCl;
        double dSiCl2_dt = k5 * SiHCl - k_5 * SiCl2;

        // Обновляем концентрации
        SiH2Cl2 += dSiH2Cl2_dt * dt;
        SiHCl += dSiHCl_dt * dt;
        HCl += dHCl_dt * dt;
        SiCl2 += dSiCl2_dt * dt;
    }
}
