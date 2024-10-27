#include "lab22.h"
#include <algorithm>
#include <random>
#include <sstream>
#include <iostream>

void Lab22::simulate_queue( double time, 
                            double dt, 
                            std::vector<double>& times, 
                            std::vector<double>& queue_lengths, 
                            std::string& conclusion) {
    std::cout << "Lab22::simulate_queue(...) entered" << std::endl;
    double queue_length = 0.0;
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    double total_people_joined = 0;
    double total_known_people = 0;

    for (double t = 0.0; t <= time; t += dt) {
        times.push_back(t);

        // Люди подходят к очереди
        double new_people = arrival_rate * dt;

        // Определяем сколько людей пристроилось к знакомому
        double known_people = 0.0;
        for (int i = 0; i < new_people; ++i) {
            if (dist(gen) <= acquaintance_prob) {
                known_people += 1.0;
            }
        }

        // Суммируем людей в очереди
        queue_length += new_people - known_people;
        queue_length = std::max(0.0, queue_length - cashier_rate * dt); // Убираем обработанных кассиром

        queue_lengths.push_back(queue_length);

        total_people_joined += new_people;
        total_known_people += known_people;
    }

    // Рассчёт сценариев в зависимости от параметров
    std::stringstream ss;
    if (total_known_people > total_people_joined * 0.1) {
        ss << "Вы часто встречаете знакомых, и ваше продвижение в очереди ускорено.\n";
    } else {
        ss << "Вы редко встречаете знакомых, и стоите в очереди обычно.\n";
    }

    if (queue_length == 0) {
        ss << "Очередь закончилась. Вы продвинулись до кассы быстро.\n";
    } else if (queue_length < total_people_joined / 2) {
        ss << "Очередь сократилась, вы продвинулись относительно быстро.\n";
    } else {
        ss << "Очередь продолжает расти, ваше продвижение замедлено.\n";
    }

    conclusion = ss.str();
}
