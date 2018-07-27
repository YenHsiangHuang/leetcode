#include <iostream>
#include <string>
// + - * / and non-negative integers
// Pass for today, will deal with it tmr!
int calculate(std::string s) {
}

int main(int argc, const char *argv[]) {
    std::cout << calculate("3+2*2") << std::endl;
    std::cout << calculate(" 3/2 ") << std::endl;
    std::cout << calculate(" 3+5 / 2 ") << std::endl;
    return 0;
}
