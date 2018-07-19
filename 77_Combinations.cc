// Not finished
#include <vector>
#include "printer.h"

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

/**
   combine(n, k) = combine(n-1, k) + {combine(n-1, k-1), n}
   Example:
       combine(2, 2) = [1, 2]

       combine(2, 1) = [1]
                       [2]

       combine(3, 2) = [1, 2]
                       [1, 3]
                       [2, 3]
 */

std::vector<std::vector<int>> combine(int n, int k) {
    std::cout << n << " " << k << std::endl;
    if (n < k || n <= 0 || k <= 0) return std::vector<std::vector<int>> ();

    std::vector<std::vector<int>> res;

    if (n == k) {
        std::vector<int> tmp;
        tmp.reserve(k);
        for (int i = 1; i <= k; ++i) tmp.push_back(i);
        res.push_back(tmp);
        return res;
    }

    if (k == 1) {
        res.reserve(n);
        for (int i = 0; i < n - 1; ++i) {
            res.push_back(std::vector<int> {i + 1});
        }
    }

    res = combine(n-1, k-1);
    printVec2(res);
    for (auto& it : res) it.push_back(n);
    printVec2(res);

    auto tmp = combine(n-1, k);
    res.insert(res.end(), tmp.begin(), tmp.end());
    return res;
}

/*
std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    res.reserve(nCr(n, k));

    combine(res, n, k);

    return res;
}
*/

int main(int argc, const char *argv[]) {
    printVec2(combine(4, 2));
    return 0;
}
