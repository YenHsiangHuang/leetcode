/**
   LC #215
   c++ equivalent: std::nth_element

   I implemented this in two ways: selection algorithm and priority queue.
 */
#include <iostream>
#include <vector>
#include <queue>
#include "printer.h"

/**
   Selection algorithm: same as the partition method in quick sort
   If we choose the pivot well, the time complexity can be O(n), but for now it's not.
 */
int partition(std::vector<int>& nums, int lb, int ub) {
    if (!(lb < ub)) return -1;
    int i = lb, j = ub;
    int pivot = nums[ub];
    while (i < j) {
        while (nums[i] >  pivot && i < j) ++i;
        while (nums[j] <= pivot && i < j) --j;
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[i], nums[ub]);

    return i;
}

int findKthLargestPartition(std::vector<int>& nums, int k) {
    size_t lb = 0, ub = nums.size() - 1;
    while (lb < ub) {
        int i = partition(nums, lb, ub);  // nums[0 ~ i-1] > nums[i]
        if (i == k - 1) break;

        if (i > k - 1)
            ub = i - 1;
        else
            lb = i + 1;
    }

    return nums[k - 1];
}

int findKthLargestPartition(std::vector<int>&& nums, int k) {
    return findKthLargestPartition(nums, k);
}

/**
   This runs with O(n) time and O(n) space. We can make it O(k) space by tracking
   the size of priority queue and pops out extra elements. It would matter a lot
   for large vector but not in here.
 */
int findKthLargestPriorityQueue(std::vector<int>& nums, int k) {
    std::priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; ++i)
        pq.pop();
    return pq.top();
}

int findKthLargestPriorityQueue(std::vector<int>&& nums, int k) {
    return findKthLargestPriorityQueue(nums, k);
}

int main(int argc, const char* argv[]) {
    std::cout << findKthLargestPartition(std::vector<int>{3, 2, 1, 5, 6, 4}, 2)
              << std::endl;  // 5
    std::cout << findKthLargestPriorityQueue(std::vector<int>{3, 2, 1, 5, 6, 4}, 2)
              << std::endl;  // 5
    std::cout << findKthLargestPartition(std::vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4)
              << std::endl;  // 4
    std::cout << findKthLargestPriorityQueue(std::vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4)
              << std::endl;  // 4
    std::cout << findKthLargestPartition(std::vector<int>{1,2}, 2)
              << std::endl;  // 1
    std::cout << findKthLargestPriorityQueue(std::vector<int>{1,2}, 2)
              << std::endl;  // 1
    return 0;
}
