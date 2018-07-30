// Find triplets that sum to zero
#include <stack>
#include <vector>
#include "printer.h"
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;

    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
        int lb = i + 1, ub = n - 1, target = -nums[i];
        while (lb < ub) {
            int tmpSum = nums[lb] + nums[ub];
            if (tmpSum > target) {
                --ub;
            } else if (tmpSum < target) {
                ++lb;
            } else {  // tmpSum == target
                res.emplace_back(std::vector<int>{nums[i], nums[lb], nums[ub]});
                while (lb < ub && nums[lb + 1] == nums[lb]) ++lb;
                while (lb < ub && nums[ub - 1] == nums[ub]) --ub;
                ++lb;
                --ub;
            }
        }
        while (nums[i + 1] == nums[i]) ++i;  // Move to next new element
    }
    return res;
}

std::vector<std::vector<int>> threeSum(std::vector<int>&& nums) {
    return threeSum(nums);
}

void runTest(std::vector<int> nums) {
    printVec(nums);
    printVec2(threeSum(nums));
}

int main(int argc, const char *argv[]) {
    runTest(std::vector<int> {1, 1, -2});
    runTest(std::vector<int> {-1, 0, 1, 2, -1, -4});
    runTest(std::vector<int> {-1, 0, 1, 1, -1, 0});
    runTest(std::vector<int> {0, 0, 0, 0, 0, 0, 0});
    runTest(std::vector<int> {INT_MIN, INT_MAX, 1, 0, -1});
    runTest(std::vector<int> {});
    return 0;
}
