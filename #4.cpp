#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include "subvector.h"

//TODO Done!

int main() {
    std::vector<int> array;
    dynamic_array<int> my_array;
    std::ofstream file_out("#4.txt");

    int number_of_elements = 100001;
    for (auto i = 1000; i < number_of_elements; i += 1000) {

        array.resize(i);
        my_array.resize(i);

        for (auto k = 0; k < my_array.size(); ++k) {
            my_array[k] = rand();
        }
        std::fill(array.begin(), array.end(), rand());

        long overall_time = 0;
        long overall_my = 0;
        for (auto j = 0; j < number_of_elements; j++) {
            auto start = std::chrono::steady_clock::now();
            array[i];
            auto finish = std::chrono::steady_clock::now();
            overall_time += std::chrono::duration_cast<std::chrono::nanoseconds>( finish - start).count();

            auto my_start = std::chrono::steady_clock::now();
            my_array[i];
            auto my_finish = std::chrono::steady_clock::now();
            overall_my += std::chrono::duration_cast<std::chrono::nanoseconds>( my_finish - my_start).count();
        }

        file_out << overall_time / (number_of_elements - 1) << " " << overall_my / (number_of_elements - 1)<< std::endl;

    }

    file_out.close();
}
