#include <string>
#include <vector>
#include <iostream>

int parseNum(std::string& s, int& i) {
    int res = 0;
    for (; i < s.length() && isdigit(s[i]); ++i) {
        res = 10 * res + s[i] - '0';
    }
    return res;
}

int parse(std::string& s, int& i) {
    std::vector<int> nums;
    char op = '+';

    for (; i < s.length() && op != ')'; ++i) {
        if (s[i] == ' ') {
            continue;
        }
        int num = s[i] == '(' ? parse(s, ++i) : parseNum(s, i);
        switch (op) {
            case '+': nums.push_back(num); break;
            case '-': nums.push_back(-num); break;
            case '*': nums.back() *= num; break;
            case '/': nums.back() /= num; break;
        }
        op = s[i];
    }

    int res = 0;
    for (auto& n : nums) {
        res += n;
    }

    return res;
}

int calculate(std::string s) {
    int i = 0;
    return parse(s, i);
}


int main(int argc, const char *argv[]) {
    std::cout << calculate("1 + 1") << std::endl;
    std::cout << calculate(" 6-4 / 2 ") << std::endl;
    std::cout << calculate("2*(5+5*2)/3+(6/2+8)") << std::endl;
    std::cout << calculate("(2+6* 3+5- (3*14/7+2)*5)+3") << std::endl;
    return 0;
}
