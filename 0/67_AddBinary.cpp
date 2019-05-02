/**
   Given two binary strings, return their sum (also a binary string).
   The input strings are both non-empty and contains only characters 1 or 0.
 */
#include <iostream>
#include <string>
std::string addBinary(std::string a, std::string b) {
    int carry = 0, digit;
    int i = a.length() - 1, j = b.length() - 1;
    std::string res;

    while (i >= 0 || j >= 0) {
        carry += (i >= 0) ? a[i--] - '0' : 0;
        carry += (j >= 0) ? b[j--] - '0' : 0;

        digit = carry;
        carry /= 2;

        res.insert(res.begin(), (digit - 2 * carry) ? '1' : '0');
    }

    if (carry != 0) res.insert(res.begin(), '1');

    return res;
}

int main(int argc, const char *argv[]) {
    std::cout << addBinary(std::string {"110"}, std::string {"11"}) << std::endl;
    return 0;
}
