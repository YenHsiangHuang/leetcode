#include <iostream>
#include <vector>
// Takes the idea of Kadane's algorithm
int maxSubArray(std::vector<int>& nums) {
    int sum = 0, maxSum = INT_MIN;
    for (auto& n : nums) {
        sum += n;
        if (sum > maxSum) maxSum = sum;
        if (sum < 0) sum = 0;
    }
    return maxSum;
}
int maxSubArray(std::vector<int>&& nums) {
    return maxSubArray(nums);
}

int main(int argc, const char *argv[]) {
    std::cout << maxSubArray(std::vector<int> {-2,1,-3,4,-1,2,1,-5,4}) << std::endl;
    std::cout << maxSubArray(std::vector<int> {-2,1}) << std::endl;
    std::cout << maxSubArray(std::vector<int> {-2}) << std::endl;
    return 0;
}
