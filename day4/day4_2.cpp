#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <array>


inline bool check_vals(char x, char y) {
    return (x == 'M' && y == 'S') || (x == 'S' && y == 'M');
}

bool check_coord(std::vector<std::string> const& input, int row_num, int col_num) {
    if (input[row_num][col_num] != 'A') {
        return false;
    }

    return check_vals(input[row_num - 1][col_num - 1], input[row_num + 1][col_num + 1]) && check_vals(input[row_num + 1][col_num - 1], input[row_num - 1][col_num + 1]);

}

int main() {
    std::ifstream file("input.txt");
    std::vector<std::string> input;
    std::string line;
    while (file >> line) {
        input.push_back(line);
    }
    int count = 0;
    for (size_t r = 1; r < input.size() - 1; ++r) {
        for (size_t c = 1; c < input[0].size() - 1; ++c) {
            count += check_coord(input, r, c);
        }
    }
    std::cout << count << std::endl;

    return 0;

}
