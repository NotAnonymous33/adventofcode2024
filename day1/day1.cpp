#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> // abs
#include <algorithm> // sort

int main() {
    std::ifstream file("day1input.txt");
    int sum = 0;
    int num1, num2;
    std::vector<int> list1, list2;

    while (file >> num1 >> num2) {
        list1.push_back(num1);
        list2.push_back(num2);
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    for (size_t i = 0; i < list1.size(); i++) {
        sum += abs(list1[i] - list2[i]);
    }

    std::cout << sum << std::endl;
    return 0;
}