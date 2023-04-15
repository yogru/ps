#include <iostream>

using namespace std;
int N = 0;
int dp[100001] = {-1};

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i <= N; i++) {
        dp[i] = -1;
    }
}


int main() {
    input();
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;

    for (int i = 6; i <= N; i++) {
        int two = dp[i - 2];
        int five = dp[i - 5];
        if (two != -1) {
            dp[i] = two + 1;
        }
        if (five != -1) {
            if (dp[i] == -1) {
                dp[i] = five + 1;
            } else {
                dp[i] = min(dp[i], five + 1);
            }
        }
    }
    cout << dp[N] << '\n';
}