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

double fractionalKnapsack(vector<Item> items, int W) {
    sort(items.begin(), items.end(), cmpRatio);
    double totalVal = 0.0;
    int curW = 0;
    for (auto &it : items) {
        if (curW + it.weight <= W) {
            curW += it.weight;
            totalVal += it.value;
        } else {
            int remain = W - curW;
            totalVal += it.value * (double(remain) / it.weight);
            break;
        }
    }
    return totalVal;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;
    cout << "Fractional Knapsack value: " << fractionalKnapsack(items, W);
    return 0;
}
