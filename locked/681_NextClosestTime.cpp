#include <string>
#include <iostream>
#include <set>
std::string nextClosestTime(std::string time) {
    // register digits
    std::set<char> digit;
    for (auto& c : time) {
        if (c != ':') {
            digit.insert(c);
        }
    }

    // last digit
    uint32_t i = 4;
    if (*digit.crbegin() > time[i]) {
        time[i] = *digit.crbegin();
        return time;
    }

    // 3rd digit
    --i;
    auto it = digit.crbegin();
    while (*it >= '6') {
        ++it;
    }
    std::cout << "3rd digit " << *it << std::endl;
    for (; it != digit.crend(); ++it) {
        if (*it > time[i]) {
            time[i] = *it;
            time[i + 1] = *digit.cbegin();
            return time;
        }
    }

    //

    return time;
}

int main(int argc, const char *argv[]) {
    std::cout << nextClosestTime("19:34") << std::endl;  // 19:39
    std::cout << nextClosestTime("05:27") << std::endl;  // 05:50
    return 0;
}
