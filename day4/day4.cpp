#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <array>

std::vector<std::array<int, 2>> product(std::vector<int> arr) {
    std::vector<std::array<int, 2>> ret;
    for (auto value1 : arr) {
        for (auto value2 : arr) {
            ret.push_back(std::array<int, 2>{value1, value2});
        }
    }
    return ret;
}

bool check_direction(std::vector<std::string> const& input, int row, int col, int dr, int dc) {
    std::string xmas = "XMAS";
    for (int i = 0; i < 4; ++i) {
        int cur_row = row + i * dr;
        int cur_col = col + i * dc;
        if (cur_row < 0 || cur_row >= input.size()) {
            return false;
        }
        if (cur_col < 0 || cur_col >= input[0].size()) {
            return false;
        }
        if (input[cur_row][cur_col] != xmas[i]) {
            return false;
        }
    }
    return true;

}


int check_coord(std::vector<std::string> const& input, int row_num, int col_num) {
    std::vector<std::array<int, 2>> directions = product(std::vector<int> {1, -1, 0});
    int count = 0;
    for (auto dir: directions) {
        if (check_direction(input, row_num, col_num, dir[0], dir[1])) {
            count++;
        }
    }

    return count;
}

int main() {
    std::ifstream file("input.txt");
    std::vector<std::string> input;
    std::string line;
    while (file >> line) {
        input.push_back(line);
    }
    int count = 0;
    for (size_t r = 0; r < input.size(); ++r) {
        for (size_t c = 0; c < input[0].size(); ++c) {
            count += check_coord(input, r, c);
        }
    }
    std::cout << count << std::endl;

    return 0;

}
