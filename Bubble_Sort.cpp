#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    vector<int> a = {5, 1, 4, 2, 8};
    bubbleSort(a);
    for (int x : a) cout << x << " ";
    return 0;
}
