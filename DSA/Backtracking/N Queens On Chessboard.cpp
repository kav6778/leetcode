#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
using namespace std;

int n = 8;
vector<int> queens;
vector<vector<int>> board(n, vector<int>(n, 0)); // intializing and setting all zeros is necessary

bool check(int row, int col) {
    for (int prow = 0; prow < row; prow++) {
        int pcol = queens[prow];
        if (pcol == col || abs(row - prow) == abs(col - pcol)) {
            return false;
        }
    }
    return true;
}

int cnt = 0; // Initialize the count to 0

void rec(int level) { // level is row
    // base case - if we placed all queens successfully, return true
    if (level == n) {
        cnt++;
        return;
    }

    // recursive case
    for (int col = 0; col < n; col++) {
        if (board[level][col] == 0 && check(level, col)) {
            // place / move
            queens.push_back(col);
            board[level][col] = 1; // Mark the cell as occupied
            rec(level + 1);
            board[level][col] = 0; // Backtrack: mark the cell as empty again
            queens.pop_back();
        }
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
    }

    // Initialize and reset the count variable before calling rec
    cnt = 0;

    rec(0);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    
    // Print the count of solutions
    cout << cnt << endl;

    return 0;
}
