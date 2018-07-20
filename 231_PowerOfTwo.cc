#include <iostream>
// Normal solution
bool isPowerOfTwo(int n) {
    int num = 0;
    while (n) {
        num += n & 1;
        if (num > 1) return false;
        n >>= 1;
    }
    return num == 1;
}

// Amazing 1-liner
bool isPowerOf2(int n) { return n > 0 && (n & (n - 1)) == 0; }

int main(int argc, const char *argv[]) {
    for (int i = -10; i < 10; ++i) {
        std::cout << i << " " << isPowerOfTwo(i) << std::endl;
        std::cout << i << " " << isPowerOf2(i) << std::endl;
    }
    return 0;
}
