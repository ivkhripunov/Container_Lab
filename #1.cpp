#include <vector>
#include "subvector.h"
#include <fstream>
#include <iostream>

//TODO Done!

int main() {
    std::vector<int> array;
    dynamic_array<int> my_array(0);
    std::ofstream file_out("#1.txt");

    for (auto i = 1; i < 4097; ++i) {
        file_out << array.capacity() << " " << my_array.size() << std::endl;
        array.push_back(1);
        my_array.push_back(1);
    }

    file_out.close();
}