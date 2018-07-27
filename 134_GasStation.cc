#include <iostream>
#include <vector>

// Time: n
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int n = gas.size();
    int net = 0, fuel = 0, res = 0;

    for (int i = 0; i < n; ++i) {
        int diff = gas[i] - cost[i];
        net += diff;
        fuel += diff;
        if (fuel < 0) {
            fuel = 0;
            res = i + 1;
        }
    }
    return (net < 0) ? -1 : res;
}

// Time: 3n
#if 0
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int n = gas.size();
    std::vector<int> net(n);
    for (int i = 0; i < n; ++i) net[i] = gas[i] - cost[i];
    for (int i = 1; i < n; ++i) net[i] += net[i - 1];

    if (net.back() != 0) return -1;

    int valley = 0, lowNet = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (net[i] >= lowNet) continue;
        lowNet = net[i];
        valley = i;
    }

    return (valley == n) ? 0 : valley + 1;
}
#endif
int canCompleteCircuit(std::vector<int>&& gas, std::vector<int>&& cost) {
    return canCompleteCircuit(gas, cost);
}

int main(int argc, const char *argv[]) {
    std::cout << canCompleteCircuit(std::vector<int> {1,2,3,4,5}, std::vector<int> {3,4,5,1,2}) << std::endl;
    std::cout << canCompleteCircuit(std::vector<int> {2,3,4}, std::vector<int> {3,4,3}) << std::endl;
    return 0;
}
