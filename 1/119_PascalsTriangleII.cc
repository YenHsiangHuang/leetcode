#include <vector>
#include "printer.h"
// A more concise backward solution
std::vector<int> getRow(int rowIndex) {
    std::vector<int> res(rowIndex + 1);
    res.front() = 1;

    for (int i = 1; i <= rowIndex; ++i)
        for (int j = i; j > 0; --j)
            res[j] += res[j - 1];

    return res;
}

#if 0
// My original solution
std::vector<int> getRow(int rowIndex) {
    std::vector<int> res;

    res.reserve(rowIndex);
    res.push_back(1);
    if (!rowIndex) return res;
    res.push_back(1);
    if (rowIndex == 1) return res;

    for (int i = 2; i <= rowIndex; ++i) {
        res.insert(res.begin() + 1, res[0] + res[1]);
        for (int j = 2; j < i; ++j) res[j] += res[j + 1];
    }

    return res;
}
#endif

int main(int argc, const char *argv[]) {
    printVec(getRow(0));
    printVec(getRow(1));
    printVec(getRow(2));
    printVec(getRow(3));
    printVec(getRow(4));
    printVec(getRow(5));
    return 0;
}
