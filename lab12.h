#ifndef LAB12_H
#define LAB12_H

/*
Для последовательной реакции:
A→B→C
Сначала найдем скорости первой и второй стадий.
*/

class Lab12 {
private:
    double k1, k2; // константы скорости

public:
    Lab12(double conversion_time, double max_concentration_time);

    void get_rates(double& k1_out, double& k2_out);
};

#endif
