#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <random>
#include "subvector.h"

//TODO Done!

std::random_device rd;
std::mt19937 gen(rd());

int random(int low, int high) {
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}

int main() {
    std::vector<int> array;
    dynamic_array<int> my_array;
    std::ofstream file_out("#2.txt");

    int number_of_elements = 100001;
    for (auto i = 1000; i < number_of_elements; i += 1000) {
        long overall_time = 0;
        long overall_my = 0;
        int number_of_attempts = 10000;
        for (auto j = 0; j < number_of_attempts; j++) {

            array.resize(i);
            my_array.resize(i);

            std::fill(array.begin(), array.end(), rand());
            auto it = array.begin() + random(1, i - 1);
            auto value = rand();
            auto start = std::chrono::steady_clock::now();
            array.insert(it, value);
            auto finish = std::chrono::steady_clock::now();
            overall_time += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

            for (auto k = 0; k < my_array.size(); ++k) {
                my_array[k] = rand();
            }
            auto index = random(0, my_array.size() - 1);
            auto my_value = rand();
            auto my_start = std::chrono::steady_clock::now();
            my_array.insert(index, my_value);
            auto my_finish = std::chrono::steady_clock::now();
            overall_my += std::chrono::duration_cast<std::chrono::nanoseconds>(my_finish - my_start).count();

        }
        std::cout << i << std::endl;

        file_out << overall_time / (number_of_attempts) << " " << overall_my / (number_of_attempts) << std::endl;

    }

    file_out.close();
}
