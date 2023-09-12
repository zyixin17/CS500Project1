//
//  main.cpp
//  p1
//
//  Created by Yixin Zhang on 2023/9/11.
//

#include <iostream>
#include <string>

std::string decode(const std::string& input) {
    std::string normal1 = "`1234567890-=";
    std::string normal2 = "QWERTYUIOP[]\\";
    std::string normal3 = "ASDFGHJKL;'";
    std::string normal4 = "ZXCVBNM,./";

    std::string shifted1 = "1234567890-";
    std::string shifted2 = "WERTYUIOP[]\\";
    std::string shifted3 = "SDFGHJKL;'";
    std::string shifted4 = "XCVBNM,./";

    std::string result = "";
    
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (shifted1.find(c) != std::string::npos) {
            result += normal1[shifted1.find(c)];
        } else if (shifted2.find(c) != std::string::npos) {
            result += normal2[shifted2.find(c)];
        } else if (shifted3.find(c) != std::string::npos) {
            result += normal3[shifted3.find(c)];
        } else if (shifted4.find(c) != std::string::npos) {
            result += normal4[shifted4.find(c)];
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string input;
    std::cout << "Enter the text: ";
    std::getline(std::cin, input);
    
    std::string decodedMessage = decode(input);
    std::cout << "Original text: " << decodedMessage << std::endl;

    return 0;
}
