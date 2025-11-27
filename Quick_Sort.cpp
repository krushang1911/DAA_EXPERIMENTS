#include <bits/stdc++.h>
using namespace std;

int partitionVec(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partitionVec(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    vector<int> a = {10, 7, 8, 9, 1, 5};
    quickSort(a, 0, (int)a.size() - 1);
    for (int x : a) cout << x << " ";
    return 0;
}
