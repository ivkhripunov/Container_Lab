#include <fstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include "subforward_list.h"
#include <forward_list>

//TODO Done!

int main() {
    std::forward_list<int> forward;
    List<int> my_forward;
    std::ofstream file_out("#5.txt");


    for (auto i = 0; i < 10000; ++i) {
        auto start = std::chrono::steady_clock::now();
        forward.push_front(rand());
        auto finish = std::chrono::steady_clock::now();
        file_out << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ";

        auto my_start = std::chrono::steady_clock::now();
        my_forward.pushFront(rand());
        auto my_finish = std::chrono::steady_clock::now();
        file_out << std::chrono::duration_cast<std::chrono::nanoseconds>(my_finish - my_start).count() << std::endl;
    }

    file_out.close();
}