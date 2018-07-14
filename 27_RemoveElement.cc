#include <vector>
int removeElement(std::vector<int>& nums, int val) {
    auto it = nums.begin();
    while (it != nums.end()) it = (*it != val) ? it + 1 : nums.erase(it);
    return nums.size();
}

int main(int argc, const char* argv[]) {
    // placeholder
    return 0;
}
