#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int minPrice = INT_MAX;
    int profit = 0;
    for (auto& p : prices) {
        minPrice = (p < minPrice) ? p : minPrice;
        profit = (p - minPrice > profit) ? p - minPrice : profit;
    }

    return profit;
}
int maxProfit(std::vector<int>&& prices) { return maxProfit(prices); }

/**
   Kadane's algorithm (largest sum of subarray):
   For each element[i], the possible max sum that "ends at element[i]" is
   either (currentMax + element[i]) or (element[i]) itself, where currentMax is
   the max sum ends at element[i - 1]

   This function takes difference array as input

   int kadane(std::vector<int>& prices) {
       if (prices.empty()) return 0;
       int maxGlo = prices[0], maxCur = prices[0];
       for (int i = 1; i < prices.size(); ++i) {
           maxCur = std::max(prices[i], maxCur + prices[i]);
           if (maxCur > maxGlo) maxGlo = maxCur;
       }
       return maxGlo;
   }
*/

// Modified Kadane's algorithm
int kadane(std::vector<int>& prices) {
    int curProfit = 0, profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        int diff = prices[i] - prices[i - 1];
        // curProfit = std::max(diff, curProfit + diff);
        curProfit = (curProfit < 0) ? diff : diff + curProfit;  // A bit optimization
        if (curProfit > profit) profit = curProfit;
    }
    return profit;
}
int kadane(std::vector<int>&& prices) { return kadane(prices); }

int main(int argc, const char* argv[]) {
    std::cout << maxProfit(std::vector<int>{7, 1, 5, 3, 6, 4}) << std::endl;
    std::cout << kadane(std::vector<int>{7, 1, 5, 3, 6, 4}) << std::endl;
    return 0;
}
