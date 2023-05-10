#include <iostream>

using namespace std;

int nap[21][101];
int weights[21];
int values[21];
int n;

void input() {
    for (int i = 0; i < 21; i++) {
        weights[i] = -1;
        values[i] = -1;
        for (int j = 0; j < 101; j++) {
            nap[i][j] = -1;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
}

int solution(int item, int weight) {
    if (item == 0)return 0;
    if (nap[item][weight] != -1)return nap[item][weight];
    nap[item][weight] = max(nap[item][weight], solution(item - 1, weight));
    int nextWeight = weight - weights[item];
    if (nextWeight > 0) {
        nap[item][weight] = max(nap[item][weight], solution(item - 1, nextWeight) + values[item]);
    }
    return nap[item][weight];
}

int main() {
    input();
    cout << solution(n, 100) << '\n';
}