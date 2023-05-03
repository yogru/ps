#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int MAP[101][101];
int visit[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


void initMap(int startX, int startY, int endX, int endY, int val) {
    for (int i = startY; i < endY; i++) {
        for (int j = startX; j < endX; j++) {
            MAP[i][j] = val;
        }
    }
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    initMap(0, 0, 101, 101, -1);
    cin >> M >> N >> K;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            visit[i][j] = false;
        }
    }
    initMap(0, 0, N, M, 0);
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        initMap(x1, y1, x2, y2, 1);
//        for (int i = 0; i < M; i++) {
//            for (int j = 0; j < N; j++) {
//                cout << MAP[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n\n";
    }
}


int dfs(int sy, int sx, int acc) {
    if (MAP[sy][sx] == 1)return 0;
    if (visit[sy][sx])return 0;
    visit[sy][sx] = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
                acc = max(acc, dfs(ny, nx, acc + 1));
            }
        }
    }
    return acc;
}


int main() {
    input();
    vector<int> resultArray;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int result = dfs(i, j, 1);
            if (result != 0) {
                resultArray.push_back(result);
            }
        }
    }
    sort(resultArray.begin(), resultArray.end());

    cout << resultArray.size() << '\n';
    for (int i = 0; i < resultArray.size(); i++) {
        cout << resultArray[i] << " ";
    }
}