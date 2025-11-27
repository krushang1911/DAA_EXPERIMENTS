#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int> &a, int key) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> a = {2, 3, 4, 10, 40};
    int key = 10;
    int idx = binarySearch(a, key);
    cout << "Index: " << idx << endl;
    return 0;
}
