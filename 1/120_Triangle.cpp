#include <iostream>
#include <vector>
int minimumTotal(std::vector<std::vector<int>>& triangle) {
    if (triangle.empty() || triangle[0].empty()) return 0;

    std::vector<int> memo(1, triangle[0][0]);
    memo.reserve(triangle.size());
    for (int i = 1; i < triangle.size(); ++i) {
        memo.push_back(memo.back() + triangle[i].back());
        for (int j = triangle[i].size() - 2; j > 0; --j)
            memo[j] = triangle[i][j] + std::min(memo[j - 1], memo[j]);
        memo[0] += triangle[i][0];
    }

    int res = INT_MAX;
    for (auto& n : memo)
        if (n < res) res = n;
    return res;
}
int minimumTotal(std::vector<std::vector<int>>&& triangle) {
    return minimumTotal(triangle);
}

int main(int argc, const char *argv[]) {
    std::cout << minimumTotal(std::vector<std::vector<int>> {{2}, {3,4}, {6,5,7}, {4,1,8,3}}) << std::endl;
    std::cout << minimumTotal(std::vector<std::vector<int>> {{1}, {-2,-5}, {3,6,9}, {-1,2,4,-3}}) << std::endl;
    std::cout << minimumTotal(std::vector<std::vector<int>>{
                     {-7},
                     {-2, 1},
                     {-5, -5, 9},
                     {-4, -5, 4, 4},
                     {-6, -6, 2, -1, -5},
                     {3, 7, 8, -3, 7, -9},
                     {-9, -1, -9, 6, 9, 0, 7},
                     {-7, 0, -6, -8, 7, 1, -4, 9},
                     {-3, 2, -6, -9, -7, -6, -9, 4, 0},
                     {-8, -6, -3, -9, -2, -6, 7, -5, 0, 7},
                     {-9, -1, -2, 4, -2, 4, 4, -1, 2, -5, 5},
                     {1, 1, -6, 1, -2, -4, 4, -2, 6, -6, 0, 6},
                     {-3, -3, -6, -2, -6, -2, 7, -9, -5, -7, -5, 5, 1}})
              << std::endl;
    return 0;
}
