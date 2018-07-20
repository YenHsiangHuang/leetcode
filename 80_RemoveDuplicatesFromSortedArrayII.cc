/**
   Remove duplicates of a sorted array "in place" and return new length.
   The same element can appear at most twice.
 */
#include <vector>
#include "printer.h"
int removeDuplicates(std::vector<int>& nums) {
    // My final code inspired by aserdega's solution
    // See my LeetCode post
    // https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/151919/C++-solution-6-lines-8ms.
    int n = nums.size();
    if (n < 2) return n;

    int pos = 2;
    for (int i = 2; i < n; ++i)
        if (nums[i] != nums[pos - 2]) nums[pos++] = nums[i];

    return pos;

/**
    // Solution aserdega, nice and pretty. But the comcept of "extra" is not
    // very intuitive.
    int extra = 0;

    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 2 - extra]) nums[i - extra] = nums[i];
        else                                ++extra;
    }

    return nums.size() - extra;
 */


/**
    // Solution v1.0, need three variables
    int cnt = 0, pos = 0, cmp = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (cnt < 2 && nums[i] == nums[cmp]) {
            ++cnt;
            nums[pos++] = nums[i];
        } else if (nums[i] != nums[cmp]) {
            cmp = pos;
            nums[pos++] = nums[i];
            cnt = 1;
        }
    }

    return pos;
 */
}


int main(int argc, const char *argv[]) {
    std::vector<int> test = {0,0,1,1,1,2,2,3,3,4};
    std::cout << removeDuplicates(test) << std::endl;
    printVec(test);

    test = {1,1,1,1,2,3,3};
    std::cout << removeDuplicates(test) << std::endl;
    printVec(test);

    test = {};
    std::cout << removeDuplicates(test) << std::endl;
    printVec(test);

    test = {4,4,4,4,4,4};
    std::cout << removeDuplicates(test) << std::endl;
    printVec(test);

    return 0;
}
