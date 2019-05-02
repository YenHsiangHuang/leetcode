/**
   Finally finished it with DFS with space pre-reservation to prevent
   reallocation of large vectors.
 */
#include <vector>
#include "printer.hpp"

typedef unsigned long long ull_t;
ull_t nCr(ull_t n, ull_t r) {
    if (r > n) return 0;
    ull_t res = 1;
    for (ull_t d = 1; d <= r; ++d) {
        res *= n--;
        res /= d;
    }
    return res;
}

void combine(std::vector<std::vector<int>>& res, std::vector<int>& tmp,
             int start, int& n, int& k) {
    if (tmp.size() == k) {
        res.push_back(tmp);
        return;
    }

    for (int i = start; i <= n; ++i) {
        tmp.push_back(i);
        combine(res, tmp, i + 1, n, k);
        tmp.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    res.reserve(nCr(n, k));
    std::vector<int> tmp;
    tmp.reserve(k);

    combine(res, tmp, 1, n, k);

    return res;
}

int main(int argc, const char* argv[]) {
    printVec2(combine(5, 2));
    return 0;
}
