// LC #75
#include <vector>
#include "printer.h"

// One-pass algorithm
void sortColors(std::vector<int>& nums) {
    int lb = 0, ub = nums.size() - 1;
    int i = lb;
    while (i <= ub) {
        switch (nums[i]) {
            case 0:
                std::swap(nums[lb++], nums[i++]);
                break;
            case 2:
                std::swap(nums[ub--], nums[i]);
                break;
            default:
                ++i;
        }
    }
}

// Count sort, a two-pass algorithm
//void sortColors(std::vector<int>& nums) {
    //size_t color[3] = {0};
    //for (int i = 0; i < nums.size(); ++i) ++color[nums[i]];

    //int i = 0;
    //for (int c = 0; c < 3; ++c) while (color[c]-- > 0) nums[i++] = c;
//}

int main(int argc, const char *argv[])
{
    //std::vector<int> nums = {2,0,2,1,1,0};
    std::vector<int> nums = {1,2,0};
    //std::vector<int> nums = {2,0,1};
    //std::vector<int> nums = {2};
    printVec(nums);
    sortColors(nums);
    printVec(nums);
    return 0;
}
