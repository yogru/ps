#include <iostream>

using namespace std;

int dp[1001] = {0,};


int main() {
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;


    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 4; i <= n; i++) {
        dp[i] = max(!dp[i - 1], !dp[i - 3]);
    }
    if (dp[n] == 1) {
        cout << "SK" << '\n';
    } else {
        cout << "CY" << '\n';
    }

}
