#include <iostream>
#include "matplotlibcpp.h" //на предупреждение внимания не обращать, вне области видимости ОС, система сборки решает
#include "lab2.h"
#include "lab7.h"
#include "lab12.h"
#include "lab17.h"

namespace plt = matplotlibcpp;

class LabsExecutor {
private:
void executeLab2() {
    double k = 0.1; // константа скорости
    double A0 = 1.0, B0 = 2.0; // начальные концентрации
    Lab2 reaction(k, A0, B0);

    double A, B, C;
    reaction.get_initial(A, B, C);

    double t = 50; // время
    reaction.compute(t, A, B, C);

    std::cout << "При времени t=" << t << ":\n";
    std::cout << "Концентрация A: " << A << "\n";
    std::cout << "Концентрация B: " << B << "\n";
    std::cout << "Концентрация C: " << C << "\n";
}

void executeLab7(){
    double half_life = 30.0; // Время полураспада (дни)
    double target_fraction = 0.01; // Целевая доля (1%)

    Lab7 decay;
    double time_to_1_percent = decay.compute_decay_time(half_life, target_fraction);
    std::cout << "Время до 1%: " << time_to_1_percent << " дней\n";
}

void executeLab12() {
    double conversion_time = 72.5; // Время 80% конверсии
    double max_concentration_time = 55.5; // Время достижения максимума B

    Lab12 reaction(conversion_time, max_concentration_time);

    double k1, k2;
    reaction.get_rates(k1, k2);

    std::cout << "Константа скорости первой стадии (k1): " << k1 << "\n";
    std::cout << "Константа скорости второй стадии (k2): " << k2 << "\n";

}

void executeLab17() {
    double k1 = 0.1, k2 = 0.05; // Константы скорости
    double eps_A = 1.0, eps_B = 2.0, eps_C = 0.5; // Коэффициенты светопоглощения

    Lab17 reaction(k1, k2, eps_A, eps_B, eps_C);

    // Векторы для хранения результатов
    std::vector<double> times, concentrations_A, concentrations_B, concentrations_C, optical_densities;

    // Вычисление концентраций и оптической плотности
    reaction.compute_concentrations(100.0, 0.1, times, concentrations_A, concentrations_B, concentrations_C, optical_densities);

    // Построение графиков
    plt::figure_size(1200, 780);
    
    // Использование named_plot для указания меток
    plt::named_plot("[A]", times, concentrations_A, "r-");
    plt::named_plot("[B]", times, concentrations_B, "g-");
    plt::named_plot("[C]", times, concentrations_C, "b-");
    plt::named_plot("Optical Density", times, optical_densities, "k--");

    // Добавление меток и заголовков
    plt::xlabel("Time");
    plt::ylabel("Concentration / Optical Density");
    plt::title("Concentration and Optical Density over Time");

    // Отображение легенды
    plt::legend();

    // Сетка и отображение
    plt::grid(true);
    
    // Сохранение графика
    std::string lab17img = "лаба17_картинка.png";
    plt::save(lab17img);
    plt::show();
    std::cout << "График сохранен как " << lab17img << std::endl;
}


public:
int Execute() {
    std::cout << "Choose lab: ";
    int choice = 0;
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice)
    {
    case 2:
        executeLab2();
        return EXIT_SUCCESS;
        break;
    case 7:
        executeLab7();
        return EXIT_SUCCESS;
        break;
    case 12:
        executeLab12();
        return EXIT_SUCCESS;
        break;
    case 17:
        executeLab17();
        return EXIT_SUCCESS;
        break;
    
    default:
    std::cout << "This lab not exists yet" << std::endl;
    return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
};
 LabsExecutor() =default;
~LabsExecutor() = default;
};