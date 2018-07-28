#include <vector>
#include "printer.h"
std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    res.reserve(numRows);
    for (int i = 0; i < numRows; ++i) res.push_back(std::vector<int> (i + 1, 1));

    for (int i = 2; i < numRows; ++i)
        for (int j = 1; j < i; ++j) res[i][j] = res[i - 1][j - 1] + res[i - 1][j];

    return res;
}

int main(int argc, const char *argv[]) {
    printVec2(generate(5));
    return 0;
}
