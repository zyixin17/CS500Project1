//
//  main.cpp
//  p3
//
//  Created by Yixin Zhang on 2023/9/11.
//

#include <iostream>

unsigned long long inverse(unsigned long long num){
    unsigned long long rem, rev = 0;
    while(num != 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    return rev;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int input_num;
    unsigned long long acc = 0;
    int ct = 0;
    std:: cout<< "Please enter a number" << std::endl;
    std::cin >> input_num;
    //std::cout<< inverse(input_num) << std::endl;
    acc += input_num;
    while(acc != inverse(acc)){
        acc += inverse(acc);
        ct++;
        //std:: cout<< acc <<std::endl;
        if (ct>99){
            std:: cout<< "iterations: " << ct << ", no palindrome found!"<< std::endl;
            return (1);
        }
    }
    std:: cout<< "palindrome:" <<acc << "," << "iterations: " <<ct << std::endl;
    return 0;
}
