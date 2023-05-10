#include <iostream>

using namespace std;

int N, K, S;
int speeds[81];
int powers[81];
int dp[81][201 * 81];

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 81; i++) {
        for (int j = 0; j < 81 * 201; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> N >> K >> S;
    for (int i = 1; i <= N; i++) {
        cin >> powers[i] >> speeds[i];
    }
}

void nap(int item, int k, int accPower) {
    if (item == 0)return;
    if (k < 0)return;
    if (dp[item][accPower] != -1)return;
    nap(item - 1, k, accPower);
    int nextAccPower = accPower + powers[item];
    if (dp[item][nextAccPower] != 1) {
        dp[item][nextAccPower] = 1;
        nap(item - 1, k - 1, nextAccPower);
    }
    return;
}

int main() {
    input();
    nap(N, K, 0);
    int result = -1;
    for (int i = 1; i < 81; i++) {
        for (int j = 1; j < 81 * 201; j++) {
            if (dp[i][j] == 1) {
                result = max(result, j * (S * K - j));
            }
        }
    }
    cout << result << '\n';

}

