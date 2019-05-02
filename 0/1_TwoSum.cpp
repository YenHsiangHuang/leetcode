#include <unordered_map>
#include <vector>
#include "printer.hpp"
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int>
        candidates;  // {index of visited value, target-visited value}
    for (int i = 0; i < nums.size(); i++) {
        int val = nums[i];
        if (candidates.count(val) > 0) {
            std::vector<int> res = {candidates[val], i};
            return res;
        }
        candidates[target - val] = i;
    }
    std::vector<int> res;
    return res;
}

void runTest(std::vector<int> test, int target) {
    printVec(test, ' ');
    std::cout << "target: " << target << std::endl;
    printVec(twoSum(test, target));
}

int main(int argc, const char *argv[]) {
    runTest(std::vector<int> {2, 7, 11, 15}, 9);
    return 0;
}
