/**
   Given a 32-bit signed integer, reverse digits of an integer

   Assume we are dealing with an environment which could only store integers
   within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
   of this problem, assume that your function returns 0 when the reversed
   integer overflows.
 */
#include <iostream>
// These lines can do magic. They reduced my runtime from 12ms to 4ms...
static auto x = []() {
    std::ios::sync_with_stdio(false);  // Turn off sync
    std::cin.tie(NULL);                // Untie I/O streams
    return 0;
}();

// One way to check overflow is simply compare the res and INT_MAX(MIN) / 10
#if 0
int reverse(int x) {
    int res = 0;

    while (x) {
        if (res > INT_MAX/10 || res < INT_MIN/10) return 0;
        int tmp = x / 10;
        res = 10 * res + x - 10 * tmp;
        x = tmp;
    }
    return res;
}
#endif

/**
   The other way is to do reverse computation. If reversion changes the number,
   it overflows.
 */
int reverse(int x) {
    int res = 0;
    while (x) {
        int div = x / 10, mod = x - 10 * div;
        int z = 10 * res + mod;
        if ((z - mod) / 10 != res) return 0;
        res = z;
        x = div;
    }
    return res;
}

int main(int argc, const char *argv[]) {
    std::cout << reverse(52) << std::endl;
    std::cout << reverse(-321) << std::endl;
    std::cout << reverse(INT_MAX) << std::endl;
    std::cout << reverse(INT_MIN) << std::endl;
    return 0;
}
