#include <iostream>
#include <vector>

// Is it just the sum of all positive difference?
int maxProfit(std::vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        int diff = prices[i] - prices[i - 1];
        profit += (diff > 0) ? diff : 0;
    }
    return profit;
}
int maxProfit(std::vector<int>&& prices) { return maxProfit(prices); }

int main(int argc, const char* argv[]) {
    std::cout << maxProfit(std::vector<int>{7, 1, 5, 3, 6, 4}) << std::endl;
    return 0;
}
