/**
   There is another Greedy method that tracks the left-most GOOD index (see
   leetcode solution for definition). But I am good with these two solutions
   right now.
 */

#include <algorithm>
#include <iostream>
#include <vector>
bool canJump(std::vector<int>& nums) {
    int n = nums.size();
    int pos = 1;
    int step = nums[0];
    while (pos < n) {
        --step;

        if (step < 0) return false;
        if (step < nums[pos]) step = nums[pos];

        ++pos;
    }
    return true;
}
bool canJump(std::vector<int>&& nums) { return canJump(nums); }

/**
   At each step, check the farest distance I can reach
 */
bool canJumpReach(std::vector<int>& nums) {
    int n = nums.size();
    int i = 0, reach = 0;
    while (i < n && i <= reach) {
        reach = std::max(i + nums[i], reach);
        ++i;
    }
    return i == n;
    // return reach >= n;  // Does not work when nums = [0]
}
bool canJumpReach(std::vector<int>&& nums) { return canJumpReach(nums); }

int main(int argc, const char* argv[]) {
    std::cout << canJump(std::vector<int>{2, 3, 1, 1, 4}) << std::endl;
    std::cout << canJump(std::vector<int>{3, 2, 1, 0, 4}) << std::endl;
    std::cout << canJump(std::vector<int>{2, 2, 0, 4}) << std::endl;
    std::cout << canJump(std::vector<int>{0, 1}) << std::endl;
    std::cout << canJump(std::vector<int>{0}) << std::endl;
    std::cout << canJumpReach(std::vector<int>{2, 3, 1, 1, 4}) << std::endl;
    std::cout << canJumpReach(std::vector<int>{3, 2, 1, 0, 4}) << std::endl;
    std::cout << canJumpReach(std::vector<int>{2, 2, 0, 4}) << std::endl;
    std::cout << canJumpReach(std::vector<int>{0, 1}) << std::endl;
    std::cout << canJumpReach(std::vector<int>{0}) << std::endl;
    return 0;
}
