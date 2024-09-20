#ifndef LAB22_H
#define LAB22_H

#include <vector>
#include <string>

class Lab22 {
private:
    double arrival_rate; // скорость прибавления людей в очередь (чел/мин)
    double cashier_rate; // скорость обработки кассиром (чел/мин)
    double acquaintance_prob; // вероятность встретить знакомого

public:
    Lab22(double arrival_rate_val, double cashier_rate_val, double acquaintance_prob_val)
        : arrival_rate(arrival_rate_val), cashier_rate(cashier_rate_val), acquaintance_prob(acquaintance_prob_val) {}

    void simulate_queue(double time, double dt, std::vector<double>& times, std::vector<double>& queue_lengths, std::string& conclusion);
};

#endif
