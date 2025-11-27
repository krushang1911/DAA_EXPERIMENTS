#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int> &pos, int row, int col) {
    for (int i = 0; i < row; i++) {
        int qCol = pos[i];
        if (qCol == col || abs(qCol - col) == abs(i - row))
            return false;
    }
    return true;
}

bool solveNQUtil(int n, int row, vector<int> &pos) {
    if (row == n) return true;
    for (int col = 0; col < n; col++) {
        if (isSafe(pos, row, col)) {
            pos[row] = col;
            if (solveNQUtil(n, row + 1, pos)) return true;
        }
    }
    return false;
}

int main() {
    int n = 8; // N-Queens
    vector<int> pos(n, -1);

    if (solveNQUtil(n, 0, pos)) {
        cout << "One solution (row:col):\n";
        for (int i = 0; i < n; i++)
            cout << i << ":" << pos[i] << "\n";

        cout << "\nBoard:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (pos[i] == j ? "Q " : ". ");
            cout << "\n";
        }
    } else {
        cout << "No solution\n";
    }
    return 0;
}
