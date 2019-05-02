#include <algorithm>
#include <iostream>
#include <vector>

/**
   BFS solution
   Traverse through each level (lb <= i <= ub).
   Upper bound is set by the farest reachable index "max of i + nums[i]" in that
   level. Lower bound is "i = current upper bound + 1".
 */
int jumpBFS(std::vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int i = 0, n = nums.size(), ub = 0, step = 0;
    while (i <= ub) {
        ++step;
        int tmp = 0;
        while (i <= ub) {
            tmp = std::max(tmp, i + nums[i]);
            if (tmp >= n - 1) return step;
            ++i;  // Upon the end of loop, i = ub + 1 = next lower bound
        }
        ub = tmp;  // max(i + nums[i]) of current level (step)
    }
    return 0;
}

int jumpBFS(std::vector<int>&& nums) { return jumpBFS(nums); }

/**
   Iterate from right to left. Record GOOD index and how many steps to the end
   starting from that index.

   -1 for bad index, >= 0 for good index
   This method is so slow that exceeds the time limit OAQ
 */
int jump(std::vector<int>& nums) {
    if (nums.size() < 2) return 0;

    int n = nums.size();
    std::vector<int> memo(n, -1);
    memo.back() = 0;

    for (int i = n - 2; i >= 0; --i) {
        if (i + nums[i] == n - 1) {
            memo[i] = 1;
            continue;
        }

        int minStep = INT_MAX;
        for (int j = i + 1; j <= i + nums[i]; ++j)
            if (memo[j] != -1 && memo[j] < minStep && memo[j] >= 0)
                minStep = memo[j];

        if (minStep != INT_MAX) memo[i] = minStep + 1;
    }
    return (memo[0] == -1) ? 0 : memo[0];
}
int jump(std::vector<int>&& nums) { return jump(nums); }

int main(int argc, const char* argv[]) {
    std::cout << jumpBFS(std::vector<int>{2, 3, 1, 1, 4}) << std::endl;
    std::cout << jumpBFS(std::vector<int>{0}) << std::endl;
    std::cout << jumpBFS(std::vector<int>{0, 1}) << std::endl;
    std::cout << jumpBFS(std::vector<int>{3, 2, 1, 0, 4}) << std::endl;
    std::cout << jumpBFS(std::vector<int>{2, 2, 0, 4}) << std::endl;
    return 0;
}
