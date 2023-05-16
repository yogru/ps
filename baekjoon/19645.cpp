#include <iostream>

using namespace std;

int N;
int values[51];
bool dp[2501][2501];
int sum = 0;

void input() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < 2501; i++) {
        for (int j = 0; j < 2501; j++) {
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        cin >> values[i];
        sum += values[i];
    }
}

void solution() {
    for (int i = 1; i <= N; i++) {
        for (int x = sum; x >= 0; x--) {
            for (int y = sum; y >= 0; y--) {
                if (x - values[i] >= 0) {
                    dp[x][y] = dp[x][y] || dp[x - values[i]][y];
                }
                if (y - values[i] >= 0) {
                    dp[x][y] = dp[x][y] || dp[x][y - values[i]];
                }
            }
        }
    }

    int result = 0;
    for (int x = sum; x >= 0; x--) {
        for (int y = sum; y >= 0; y--) {
            if (dp[x][y] && x >= y && y >= sum - x - y) {
                result = max(result, sum - x - y);
            }
        }
    }
    cout << result;
}


int main() {
    input();
    solution();
}
