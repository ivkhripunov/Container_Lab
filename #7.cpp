#include <iostream>
#include <fstream>
#include <vector>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <chrono>

int main() {
    std::vector<int> vector;
    std::forward_list<int> forward_list;
    std::list<int> list;
    std::map<int, int> map;
    std::set<int> set;
    std::ofstream file_out("#7.txt");

    for (auto i = 1000; i < 100001; i += 1000) {
        vector.resize(i);
        list.resize(i);
        forward_list.clear();
        map.clear();
        set.clear();

        std::fill(vector.begin(), vector.end(), rand());
        std::fill(list.begin(), list.end(), rand());

        for (auto j = 0; j < i; ++j) {
            forward_list.push_front(rand());
            map[j] = rand();
        }

        while (set.size() < i) set.insert(rand());

        int number_of_attempts = 1000;
        long vector_time = 0;
        long list_time = 0;
        long forward_list_time = 0;
        long map_time = 0;
        long set_time = 0;

        for (auto k = 0; k < number_of_attempts; ++k) {

            auto start = std::chrono::steady_clock::now();
            for (auto &element: vector) element += 1;
            auto finish = std::chrono::steady_clock::now();
            vector_time += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

            start = std::chrono::steady_clock::now();
            for (auto &element: list) element += 1;
            finish = std::chrono::steady_clock::now();
            list_time += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

            start = std::chrono::steady_clock::now();
            for (auto &element: forward_list) element += 1;
            finish = std::chrono::steady_clock::now();
            forward_list_time += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

            start = std::chrono::steady_clock::now();
            for (auto &element: map) element.second += 1;
            finish = std::chrono::steady_clock::now();
            map_time += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();

            start = std::chrono::steady_clock::now();
            for (auto element: set) element += 1;
            finish = std::chrono::steady_clock::now();
            set_time += std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();


        }

        file_out << vector_time / number_of_attempts << " " << forward_list_time / number_of_attempts << " "
                 << list_time / number_of_attempts << " " << map_time / number_of_attempts << " "
                 << set_time / number_of_attempts << std::endl;
    }

    file_out.close();
}
