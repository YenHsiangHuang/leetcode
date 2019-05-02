#include <vector>

int firstMissingPositive(std::vector<int>& nums) {
    int i = 0;
    int n = nums.size();

    while (i < n) {
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            std::swap(nums[i], nums[nums[i] - 1]);
        else
            ++i;
    }

    for (i = 0; i < n; ++i)
        if (nums[i] != i + 1) return i + 1;

    return n + 1;
}

int main(int argc, const char* argv[]) {
    // placeholder
    return 0;
}
