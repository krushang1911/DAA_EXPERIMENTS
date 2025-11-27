#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int> &a, int key) {
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] == key) return i;
    return -1;
}

int main() {
    vector<int> a = {10, 23, 45, 70, 11, 15};
    int key = 70;
    int idx = linearSearch(a, key);
    cout << "Index: " << idx << endl;
    return 0;
}
