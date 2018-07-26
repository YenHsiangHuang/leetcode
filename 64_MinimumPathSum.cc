#include <iostream>
#include <vector>
int minPathSum(std::vector<std::vector<int>>& grid) {
    if (grid.empty()) return 0;

    int m = grid.size(), n = grid[0].size();
    std::vector<int> memo(grid[0].begin(), grid[0].end());
    for (int j = 1; j < n; ++j) memo[j] += memo[j - 1];

    for (int i = 1; i < m; ++i) {
        memo[0] += grid[i][0];
        for (int j = 0; j < n; ++j)
            memo[j] = grid[i][j] + std::min(memo[j - 1], memo[j]);
    }
    return memo.back();
}
int minPathSum(std::vector<std::vector<int>>&& grid) {
    return minPathSum(grid);
}

int main(int argc, const char *argv[]) {
    std::cout << minPathSum(std::vector<std::vector<int>> {{1,3,1}, {1,5,1}, {4,2,1}}) << std::endl;
    return 0;
}
