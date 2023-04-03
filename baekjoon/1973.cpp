#include <iostream>
#include <cstring>

using namespace std;
#define MAX 500

int n;
int MAP[MAX][MAX];
int DP[MAX][MAX];


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void input() {
    memset(DP, -1, sizeof(DP));
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> MAP[i][j];
        }
    }
}

int dfs(int sy, int sx) {
    if (DP[sy][sx] != -1) {
        return DP[sy][sx];
    }
    DP[sy][sx] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if ((0 <= nx && nx < n) && (0 <= ny && ny < n)) {
            if (MAP[sy][sx] < MAP[ny][nx]) {
                DP[sy][sx] = max(DP[sy][sx], dfs(ny, nx) + 1);
            }
        }
    }
    return DP[sy][sx];
}

void getAnswer() {
    int ret = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // cout << DP[i][j] << ' ';
            ret = max(ret, DP[i][j]);
        }
        // cout << '\n';
    }
    cout << ret << '\n';
}

int main() {
    input();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dfs(i, j);
        }
    }
    getAnswer();
}