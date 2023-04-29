#include <iostream>
#include <deque>


using namespace std;

int R = 0;
int C = 0;
char MAP[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int result = -1;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string a;
        cin >> a;
        const char *str = a.c_str();
        for (int j = 0; j < C; j++) {
            MAP[i][j] = str[j];
        }
    }
}

struct Node {
    int count;
    int x;
    int y;

};

void answer(int sy, int sx) {
    if (MAP[sy][sx] == 'W')return;

    bool visit[50][50];
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            visit[i][j] = false;
        }
    }

    deque<Node> dq;
    Node n;
    n.count = 0;
    n.x = sx;
    n.y = sy;
    dq.push_back(n);
    visit[sy][sx] = true;
    while (!dq.empty()) {
        Node current = dq.front();
        dq.pop_front();
        if (current.count > result) {
            result = current.count;
        }
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if ((0 <= nx && nx < C) && (0 <= ny && ny < R)) {
                if (MAP[ny][nx] == 'L' && (!visit[ny][nx])) {
                    Node nextNode;
                    visit[ny][nx] = true;
                    nextNode.x = nx;
                    nextNode.y = ny;
                    nextNode.count = current.count + 1;
                    dq.push_back(nextNode);
                }
            }
        }
    }
}


int main() {
    input();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            answer(i, j);
        }
    }
    cout << result << '\n';
}