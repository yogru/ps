#include <iostream>

#define INF 987654321

int n;
int m;
int r;
int items[101];
int map[101][101];

using namespace std;

void input() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            map[i][j] = INF;
    }

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        cin >> items[i + 1];
    }
    for (int i = 0; i < r; i++) {
        int a;
        int b;
        int w;
        cin >> a >> b >> w;
        map[a][b] = map[b][a] = w;
    }

}


int solution() {
    for (int v = 1; v <= n; v++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if (v == a || v == b) continue;
                if (a == b) map[a][b] = 0;
                int newDistance = map[a][v] + map[v][b];
                if (map[a][b] > newDistance)map[a][b] = newDistance;
            }
        }
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        int current = 0;
        for (int j = 1; j <= n; j++) {
            if (map[i][j] <= m) {
                current += items[j];
            }
        }
        result = max(result, current);
    }
    return result;
}

int main() {
    input();
    cout << solution();
    return 0;
}