#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool cmpJob(const Job &a, const Job &b) {
    return a.profit > b.profit;
}

int main() {
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    sort(jobs.begin(), jobs.end(), cmpJob);

    int maxDeadline = 0;
    for (auto &j : jobs) maxDeadline = max(maxDeadline, j.deadline);
    vector<char> slot(maxDeadline + 1, 0);
    int totalProfit = 0;

    for (auto &j : jobs) {
        for (int t = j.deadline; t > 0; t--) {
            if (slot[t] == 0) {
                slot[t] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }

    cout << "Selected jobs: ";
    for (int t = 1; t <= maxDeadline; t++)
        if (slot[t]) cout << slot[t] << " ";
    cout << "\nTotal Profit: " << totalProfit << endl;
    return 0;
}
