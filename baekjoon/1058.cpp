#include <iostream>

using namespace std;

int N = 0;
bool ADJ[50][50];
int MAP[50][50];

void input() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++) {
            ADJ[i][j] = false;
            MAP[i][j] = 0;
        }

    cin >> N;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        const char *temC = temp.c_str();
        for (int j = 0; j < N; j++) {
            if (temC[j] == 'Y') {
                ADJ[i][j] = true;
            }
        }
    }
}

int solution() {
    for (int t = 0; t < N; t++) {
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                if (a == b)continue;
                if (ADJ[a][b] || (ADJ[a][t] && ADJ[t][b])) MAP[a][b] = 1;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        int acc = 0;
        for (int j = 0; j < N; j++) {
            acc += MAP[i][j];
        }
        result = max(result, acc);
    }
    return result;
}

int main() {
    input();
    cout << solution();
    return 0;
}