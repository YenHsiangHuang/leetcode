#include <algorithm>
#include <iostream>
#include <vector>

#define avg(lo, hi) ( (lo + hi - 1) >> 1 )

#define USE_STD
#ifdef USE_STD
// std::lower_bound
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    const size_t ROW = matrix.size();
    if (ROW == 0) return false;
    const size_t COL = matrix[0].size();
    if (COL == 0) return false;
    std::vector<int> row_end;
    for (int r = 0; r < ROW; ++r)
        row_end.push_back(matrix[r][COL - 1]);

    auto iter = std::lower_bound(row_end.cbegin(), row_end.cend(), target);
    if (iter == row_end.end()) return false;

    size_t row = iter - row_end.begin();
    iter = std::lower_bound(matrix[row].cbegin(), matrix[row].cend(), target);
    return iter != matrix[row].end() && *iter == target;
}

#else
// binary search
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    const size_t ROW = matrix.size();
    if (ROW == 0) return false;
    const size_t COL = matrix[0].size();
    if (COL == 0) return false;

    size_t lo = 0, hi = ROW*COL - 1;
    while (lo != hi) {
        size_t mid = avg(lo, hi);
        if (target > matrix[mid/COL][mid%COL])
            lo = mid + 1;
        else
            hi = mid;
    }

    return target == matrix[lo/COL][lo%COL];
}
#endif

int main(int argc, const char *argv[]) {
    std::vector<std::vector<int>> matrix = {
        { 1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };

    std::cout << searchMatrix(matrix, 30) << std::endl;

    return 0;
}
