#include <fstream>
#include <iostream>

#include <cmath> // abs
#include <vector>
#include <sstream>

bool is_valid(std::vector<int> list) {
    int direction;
    if (list[0] > list[1]) {
        direction = -1;
    } else {
        direction = 1;
    }

    for (size_t i = 0; i < list.size() - 1; i++) {
        // check all increasing or decreasing
        if (direction * (list[i + 1] - list[i]) <= 0) {
            return false;
        }

        int diff = abs(list[i + 1] - list[i]);
        if (diff > 3 || diff < 1) {
            return false;
        }
    }

    return true;

}

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        std::vector<int> numbers;
        std::istringstream lineStream(line);
        int num;
        while (lineStream >> num) {
            numbers.push_back(num);
        }
        if (is_valid(numbers)) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}