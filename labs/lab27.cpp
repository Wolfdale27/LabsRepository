#include "lab27.h"

double Lab27::reaction_rate(double H2_concentration, double M_concentration) {
    // Метод стационарных концентраций для промежуточных радикалов H.
    double h_concentration = (k1 * H2_concentration * M_concentration) / (k2 * H2_concentration + k3 * M_concentration);

    // Скорость конверсии пара-водорода
    return k2 * H2_concentration * h_concentration;
}
