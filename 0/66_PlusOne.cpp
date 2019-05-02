#include <vector>
#include "printer.hpp"
std::vector<int> plusOne(std::vector<int>& digits) {
    digits.back() += 1;
    int carry = digits.back() / 10;
    digits.back() = digits.back() - 10 * carry;

    for (auto it = digits.rbegin() + 1; carry > 0 && it != digits.rend(); ++it) {
        *it += carry;
        carry = *it / 10;
        *it = *it - 10 * carry;
    }

    if (carry > 0) digits.emplace(digits.begin(), carry);

    return digits;
}
std::vector<int> plusOne(std::vector<int>&& digits) {
    return plusOne(digits);
}


int main(int argc, const char *argv[]) {
    auto test = plusOne(std::vector<int> {9});
    printVec(test);
    return 0;
}
