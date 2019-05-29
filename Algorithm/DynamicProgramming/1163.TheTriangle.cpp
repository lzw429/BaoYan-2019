/**
The Triangle
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 60969		Accepted: 36540
Description

7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

(Figure 1)
Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right.
Input

Your program is to read from standard input. The first line contains one integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.
Output

Your program is to write to standard output. The highest sum is written as an integer.
Sample Input

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Sample Output

30
Source

IOI 1994
 */

#include <iostream>

using namespace std;

const int maxn = 105;
int n;
int ans;
int tri[maxn][maxn];
int dp[maxn][maxn];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> tri[i][j];
        }
    }
}

void solve() {
    dp[0][0] = tri[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
        }
    }

    for (int j = 0; j < n; j++) {
        ans = max(ans, dp[n - 1][j]);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    input();
    solve();
    cout << ans << endl;
    return 0;
}
