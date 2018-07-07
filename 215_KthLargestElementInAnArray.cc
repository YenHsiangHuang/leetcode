// LC #215
// c++ equivalent: std::nth_element
#include <iostream>
#include <vector>
#include "printer.h"

int findKthLargest(std::vector<int>& nums, int k) {
    printVec(nums);
    return k;
}

int findKthLargest(std::vector<int>&& nums, int k) {
    return findKthLargest(nums, k);
}

int main(int argc, const char* argv[]) {
    std::cout << findKthLargest(std::vector<int>{3, 2, 1, 5, 6, 4}, 2)
              << std::endl;
    std::cout << findKthLargest(std::vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4)
              << std::endl;
    return 0;
}

