#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

int N;
int BUILD[501];
int COUNT[501];
int ADJ[501][501];
int ANSWER[501];


void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    memset(ANSWER, -1, sizeof(ANSWER));

    for (int i = 1; i <= N; i++) {
        int num;
        int j = 0;
        while (cin >> num) {
            if (num == -1)
                break;
            if (j == 0) {
                BUILD[i] = num;
            } else {
                COUNT[i] += 1;
                ADJ[num][i] = 1;
            }
            j++;
        }
    }
}

void sol() {
    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        if (COUNT[i] == 0) {
            dq.push_back(i);
            ANSWER[i] = BUILD[i];
        }
    }

    while (!dq.empty()) {
        int target = dq.front();
        dq.pop_front();
        for (int i = 1; i <= N; i++) {
            if (ADJ[target][i] == 1) {
                COUNT[i] -= 1;
                ANSWER[i] = max(ANSWER[target], ANSWER[i]);
                if (COUNT[i] == 0) {
                    ANSWER[i] += BUILD[i];
                    dq.push_back(i);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ANSWER[i] << '\n';
    }
}

int main() {
    input();
    sol();
}