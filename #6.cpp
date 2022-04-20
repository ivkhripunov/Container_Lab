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
    std::ofstream file_out("#6.txt");

    for (auto j = 0; j < 100001; ++j) {
        forward.push_front(rand());
        my_forward.pushFront(rand());
    }

    for (auto i = 0; i < 90000; ++i) {
        auto start = std::chrono::steady_clock::now();
        forward.pop_front();
        auto finish = std::chrono::steady_clock::now();
        file_out << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << " ";

        auto my_start = std::chrono::steady_clock::now();
        my_forward.popFront();
        auto my_finish = std::chrono::steady_clock::now();
        file_out << std::chrono::duration_cast<std::chrono::nanoseconds>(my_finish - my_start).count() << std::endl;
    }

    file_out.close();
}