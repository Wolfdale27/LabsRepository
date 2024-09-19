#ifndef LAB7_H
#define LAB7_H

/*
Для реакции первого порядка можем использовать уравнение:
N(t)=N0*e^-kt

Где N0— начальное количество вещества, N(t) — количество вещества 
в момент времени t,k - константа скорости.

Пусть за 30 дней распадается 50% вещества:

            0.5=e^(-k*30)
*/


class Lab7 {
public:
    double compute_decay_time(double half_life, double target_fraction);
};

#endif
