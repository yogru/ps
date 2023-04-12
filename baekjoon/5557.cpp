#include <iostream>
#include <string>
#include<vector>

using namespace std;

int N;
int ARR[100] = {0,};
long long DP[21] = {0,};

void input() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ARR[i];
    }
}


long long solve(int depth) {
    if (depth >= N - 1) {
        return DP[ARR[N - 1]];
    }
    long long temp[21] = {0,};
    int next;
    for (int num = 0; num <= 20; ++num)
        if (DP[num] > 0) {
            next = num - ARR[depth];
            if (next >= 0) {
                temp[next] += DP[num];
            }
            next = num + ARR[depth];
            if (next <= 20) {
                temp[next] += DP[num];
            }
        }

    for (int i = 0; i <= 20; ++i)
        DP[i] = temp[i];

    return solve(depth + 1);
}


int main() {
    input();
    DP[ARR[0]] = 1;
    cout << solve(1) << '\n';
}


