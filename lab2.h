#ifndef LAB2_H
#define LAB2_H


/*
Задача №2: Аналитическая зависимость концентрации реагентов
Реакция 2A + B → C, имеет первый порядок по каждому реагенту. Это означает, что уравнения скоростей имеют вид:

d[A]/dt = -k * [A]² * [B]
d[B]/dt = -k * [A]² * [B]
d[C]/dt = k * [A]² * [B]
Но так как САо != СВо, аналитическое решение сложнее и требует численного решения.

*/

class Lab2 {
private:
    double k; // константа скорости
    double A0, B0; // начальные концентрации A и B
    double C; // концентрация C

public:
    Lab2(double k_val, double A_init, double B_init)
        : k(k_val), A0(A_init), B0(B_init), C(0) {}

    // Решение уравнений при времени t
    void compute(double t, double& A, double& B, double& C);

    // Получение начальных значений
    void get_initial(double& A, double& B, double& C) {
        A = A0;
        B = B0;
        C = 0;
    }
};

#endif
