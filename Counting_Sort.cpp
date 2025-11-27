#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &a) {
    if (a.empty()) return;
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> count(maxVal + 1, 0);
    for (int x : a) count[x]++;
    int idx = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i]--) a[idx++] = i;
    }
}

int main() {
    vector<int> a = {1, 4, 1, 2, 7, 5, 2};
    countingSort(a);
    for (int x : a) cout << x << " ";
    return 0;
}
