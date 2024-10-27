#ifndef LAB32_H
#define LAB32_H

#include <vector>

/*
  Класс Lab32 моделирует процесс разложения дихлорэтана SiH2Cl2.
  
  Реакция описана несколькими стадиями с константами скоростей для каждой реакции:
  (I) SiH2Cl2 ⇔ SiHCl + HCl (k1, k-1)
  (II) SiHCl + SiH2Cl2 ⇔ HCl2SiSiH2Cl (k2, k-2)
  (III) HCl2SiSiH2Cl ⇔ HCl2SiSiCl + H2 (k3, k-3)
  (IV) HCl2SiSiCl ⇔ HClSiSiCl2 (k4, k-4)
  (V) HClSiSiCl2 ⇔ SiHCl + SiCl2 (k5, k-5)
  
  Цель: Смоделировать изменение концентраций каждого вещества во времени
  в зависимости от констант скоростей реакций. Каждая реакция может быть обратимой.
  
  Метод simulate_reaction() решает систему дифференциальных уравнений
  для концентраций веществ и сохраняет результаты для визуализации.
  
  Начальные концентрации:
  - SiH2Cl2 = 1.0 (единица концентрации) 
  - SiHCl = 0.0
  - HCl = 0.0
  - SiCl2 = 0.0
  
  Моделирование происходит на заданном интервале времени с шагом dt.
 */
class Lab32 {
private:
    // Константы скорости реакции для каждого шага
    double k1, k_1, k2, k_2, k3, k_3, k4, k_4, k5, k_5;
    
public:
    /**
     * Конструктор инициализирует все константы скорости реакции.
     * @param k1_val, k_1_val - скорости для первой реакции (прямая и обратная)
     * @param k2_val, k_2_val - скорости для второй реакции (прямая и обратная)
     * @param k3_val, k_3_val - скорости для третьей реакции (прямая и обратная)
     * @param k4_val, k_4_val - скорости для четвертой реакции (прямая и обратная)
     * @param k5_val, k_5_val - скорости для пятой реакции (прямая и обратная)
     */
    Lab32(double k1_val, double k_1_val, double k2_val, double k_2_val, 
          double k3_val, double k_3_val, double k4_val, double k_4_val, 
          double k5_val, double k_5_val);

    /**
     * Метод для моделирования процесса разложения SiH2Cl2.
     * Решает систему дифференциальных уравнений для концентраций веществ.
     * 
     * @param time - общее время моделирования
     * @param dt - шаг по времени
     * @param times - вектор для хранения значений времени
     * @param SiH2Cl2_conc - вектор для концентрации SiH2Cl2
     * @param SiHCl_conc - вектор для концентрации SiHCl
     * @param HCl_conc - вектор для концентрации HCl
     * @param SiCl2_conc - вектор для концентрации SiCl2
     * 
     * Концентрации на каждом шаге вычисляются с использованием метода Эйлера,
     * на основе дифференциальных уравнений для каждой реакции.
     */
    void simulate_reaction(double time, double dt, 
                           std::vector<double>& times,
                           std::vector<double>& SiH2Cl2_conc,
                           std::vector<double>& SiHCl_conc,
                           std::vector<double>& HCl_conc,
                           std::vector<double>& SiCl2_conc);
};

#endif
