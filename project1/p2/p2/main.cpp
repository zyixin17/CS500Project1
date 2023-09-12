//
//  main.cpp
//  p2
//
//  Created by Yixin Zhang on 2023/9/11.
//
#include <iostream>
#include <string>
#include <vector>

std::string maps[10][5] = {
    {" - ", "| |", "   ", "| |", " - "},  // 0
    {"   ", "  |", "   ", "  |", "   "},  // 1
    {" - ", "  |", " - ", "|  ", " - "},  // 2
    {" - ", "  |", " - ", "  |", " - "},  // 3
    {"   ", "| |", " - ", "  |", "   "},  // 4
    {" - ", "|  ", " - ", "  |", " - "},  // 5
    {" - ", "|  ", " - ", "| |", " - "},  // 6
    {" - ", "  |", "   ", "  |", "   "},  // 7
    {" - ", "| |", " - ", "| |", " - "},  // 8
    {" - ", "| |", " - ", "  |", " - "}   // 9
};

std::vector<std::string> enlargeDigit(int digit, int size) {
    std::vector<std::string> enlarged;
    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            std::string line = " ";
            for (int s = 0; s < size; ++s) {
                line += maps[digit][i][1];
            }
            line += " ";
            enlarged.push_back(line);
        } else {
            std::string line(1, maps[digit][i][0]);
            for (int m = 0; m < size; ++m) {
                line += " ";
            }
            line += maps[digit][i][2];
            for (int s = 0; s < size; ++s) {
                enlarged.push_back(line);
            }
        }
    }
    return enlarged;
}

void printer(const std::string& number, int size) {
    for (int row = 0; row < 2 * size + 3; ++row) {
        for (char ch : number) {
            int digit = ch - '0';
            std::cout << enlargeDigit(digit, size)[row] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int s;
    std::string n;
    std::cin >> s >> n;
    if (s == 0 || n == "0" ){
        return 0;
    }
    printer(n, s);
    std::cout << std::endl;
    
    return 0;
}
