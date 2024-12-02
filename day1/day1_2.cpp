#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath> // abs
#include <algorithm> // sort

int main() {
    std::ifstream file("day1input.txt");
    int ans = 0;
    int num1, num2;
    std::vector<int> list1;
    std::map<int, int> counter;

    while (file >> num1 >> num2) {
        list1.push_back(num1);
        if (counter.count(num2) == 0) {
            counter[num2] = 1;
        } else {
            counter[num2]++;
        }
    }

    for (size_t i = 0; i < list1.size(); i++) {
        ans += list1[i] * counter[list1[i]];
    }


    std::cout << ans << std::endl;


}