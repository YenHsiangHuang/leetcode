#include <iostream>
#include <string>
#include <sstream>
// Concise solution usint istringstream by StefanPochman
int calculateTest(std::string s) {
    std::istringstream input('+' + s + '+');
    long long res = 0, tmpRes = 0, num;
    char op;
    while (input >> op) {
        if (op == '+' or op == '-') {
            res += tmpRes;
            input >> tmpRes;  // Read next number
            tmpRes *= 44 - op;  // tmpRes *= (op == '+') ? 1 : -1;
        } else {  // Read *, /
            input >> num;  // Read next number
            if (op == '*') {
                tmpRes *= num;
            } else {
                tmpRes /= num;
            }
        }
    }
    return res;
}



// + - * / and non-negative integers
int calculate(std::string s) {
    int num = 0, tmpRes = 0, res = 0;
    char op = '+';

    for (int i = s.find_first_not_of(' '); i < s.length();
         i = s.find_first_not_of(' ', i)) {
        if (s[i] >= '0' and s[i] <= '9') {  // is digit
            // Read all consecutive digits
            while (s[i] >= '0' && s[i] <= '9') num = 10 * num + s[i++] - '0';

            switch (op) {  // op is previous stored operator
                case '+':
                    tmpRes += num;
                    break;
                case '-':
                    tmpRes -= num;
                    break;
                case '*':
                    tmpRes *= num;
                    break;
                case '/':
                    tmpRes /= num;
                    break;
            }
            num = 0;
        } else {
            if (s[i] == '+' or s[i] == '-') {  // Sum up to final result
                res += tmpRes;
                tmpRes = 0;
            }
            op = s[i++];  // Store this operator
        }
    }

    return res + tmpRes;
}

int main(int argc, const char *argv[]) {
    std::cout << calculate("3+2*2") << std::endl;           // 7
    std::cout << calculate(" 3/2 ") << std::endl;           // 1
    std::cout << calculate(" 3+5 / 2 ") << std::endl;       // 5
    std::cout << calculate(" 33+5 / 22 ") << std::endl;      // 35
    std::cout << calculateTest(" 33 5 22 ") << std::endl;  // 35
    return 0;
}
