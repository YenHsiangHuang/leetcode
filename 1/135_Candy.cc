#include <cstdlib>
#include <ctime>
#include <vector>
#include "matlab.h"
#include "printer.h"
/**
   There is a one-pass algorithm on leetcode but I cannot understand it. Maybe I
   will try again some other time.
 */
int candy(std::vector<int>& ratings) {
    std::vector<int> nums(ratings.size(), 1);
    // First pass from left to right
    for (int i = 0; i < ratings.size() - 1; ++i) {
        if (ratings[i + 1] > ratings[i]) {
            nums[i + 1] = nums[i] + 1;
        }
    }

    // Second pass from right to left and count candies
    int res = 0;
    for (int i = ratings.size() - 1; i > 0; --i) {
        if (ratings[i - 1] > ratings[i]) {
            nums[i - 1] = std::max(nums[i - 1], nums[i] + 1);
        }
        res += nums[i];
    }
    res += nums[0];
    printVec(nums);
    return res;
}
int candy(std::vector<int>&& ratings) {
    return candy(ratings);
}

void runTest(int ub, size_t len) {
    std::vector<int> test = randi(ub, len);
    printVec(test);
    std::cout << candy(test) << std::endl;
}

void runTest(int lb, int ub, size_t len) {
    std::vector<int> test = randi(lb, ub, len);
    printVec(test);
    std::cout << candy(test) << std::endl;
}

int main(int argc, const char *argv[]) {
    runTest(10, 5);
    runTest(-10, 10, 5);
    runTest(10, 8);
    runTest(-10, 20, 8);
    return 0;
}
