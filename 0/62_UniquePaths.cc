#include <iostream>
#include <vector>
int uniquePaths(int m, int n) {
    if (!(m * n)) return 0;

    std::vector<int> memo(m, 1);
    while (n-- > 1)
        for (int i = 1; i < m; ++i) memo[i] += memo[i - 1];
    return memo.back();
}

int main(int argc, const char *argv[]) {
    std::cout << uniquePaths(2, 3) << std::endl;
    std::cout << uniquePaths(7, 3) << std::endl;
    std::cout << uniquePaths(1, 1) << std::endl;
    std::cout << uniquePaths(0, 1) << std::endl;
    std::cout << uniquePaths(1, 0) << std::endl;
    std::cout << uniquePaths(0, 0) << std::endl;
    return 0;
}
