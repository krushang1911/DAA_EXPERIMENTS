#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool cmpFinish(const Activity &a, const Activity &b) {
    return a.finish < b.finish;
}

int main() {
    vector<Activity> arr = {
        {1, 2}, {3, 4}, {0, 6},
        {5, 7}, {8, 9}, {5, 9}
    };

    sort(arr.begin(), arr.end(), cmpFinish);

    cout << "Selected activities (start,finish):\n";
    int last = 0;
    cout << "(" << arr[0].start << "," << arr[0].finish << ")\n";
    for (int i = 1; i < (int)arr.size(); i++) {
        if (arr[i].start >= arr[last].finish) {
            cout << "(" << arr[i].start << "," << arr[i].finish << ")\n";
            last = i;
        }
    }
    return 0;
}
