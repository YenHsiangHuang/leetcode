#include <vector>
int missingNumber(std::vector<int>& nums) {
    int test = 0;
    for (int i = 0; i <= nums.size(); ++i) test ^= i;
    for (auto& it : nums)                  test ^= it;
    return test;
}

int main(int argc, const char* argv[]) {
    // placeholder
    return 0;
}
