// Remove duplicates of a sorted array "in place" and return new length.
#include <vector>
#include "printer.h"
int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int pos = 0;
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != nums[pos]) nums[++pos] = nums[i];

    return pos + 1;
}

int main(int argc, const char *argv[]) {
    std::vector<int> test = {0,0,1,1,1,2,2,3,3,4};
    std::cout << removeDuplicates(test) << std::endl;
    printVec(test);
    return 0;
}
