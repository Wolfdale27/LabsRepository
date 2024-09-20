#ifndef LAB27_H
#define LAB27_H

class Lab27 {
private:
    double k1, k2, k3; // константы скорости реакций

public:
    Lab27(double k1_val, double k2_val, double k3_val)
        : k1(k1_val), k2(k2_val), k3(k3_val) {}

    double reaction_rate(double H2_concentration, double M_concentration);
};

#endif
