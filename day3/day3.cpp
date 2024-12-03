#include <iostream>
#include <fstream>
#include <regex>


int main()
{
    std::ifstream file("input.txt");
    std::string input;
    std::string line;
    int result = 0;
    while (std::getline(file, line))
    {
        input += line;
    }

    std::regex pattern(R"(mul\([0-9]+,[0-9]+\))");
    std::smatch match;

    std::regex_search(input, match, pattern);
    
    auto words_begin = std::sregex_iterator(input.begin(), input.end(), pattern);
    auto words_end = std::sregex_iterator();


    for (auto i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        int a,b;
        sscanf(match_str.c_str(), "mul(%d,%d)", &a, &b);
        result += a * b;
    }
    std::cout << result << std::endl;


}