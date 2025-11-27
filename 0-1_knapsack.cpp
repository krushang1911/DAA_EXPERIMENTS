#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

bool cmpRatio(const Item &a, const Item &b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int greedy01Knapsack(vector<Item> items, int W) {
    sort(items.begin(), items.end(), cmpRatio);
    int curW = 0, totalVal = 0;
    for (auto &it : items) {
        if (curW + it.weight <= W) {
            curW += it.weight;
            totalVal += it.value;
        }
    }
    return totalVal;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;
    cout << "Greedy 0/1 Knapsack value: " << greedy01Knapsack(items, W);
    return 0;
}
