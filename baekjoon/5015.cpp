#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool match(string p, string s) {
    int dp[101][101];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int r = 1; r <= p.size(); r++) {
        for (int c = 1; c <= s.size(); c++) {
            if (p[r - 1] == '*') {
                int target = -1;
                for (int cc = 0; cc <= s.size(); cc++) {
                    if (dp[r - 1][cc] == 1) {
                        target = cc;
                        break;
                    }
                }
                if (target != -1) {
                    for (int c2 = target; c2 <= s.size(); c2++) {
                        dp[r][c2] = 1;
                    }
                }
                continue;
            }
            if (dp[r - 1][c - 1] == 1 && p[r - 1] == s[c - 1]) {
                dp[r][c] = 1;
                continue;
            }
            dp[r][c] = 0;
        }
    }
    return dp[p.size()][s.size()] == 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string pattern;
    string countStr;
    getline(cin, pattern);
    getline(cin, countStr);
    vector<string> v;
    for (int i = 0; i < stoi(countStr); i++) {
        string d;
        getline(cin, d);
        v.push_back(d);
    }

    for (int i = 0; i < v.size(); i++) {
        if (match(pattern, v[i])) {
            cout << v[i] << '\n';
        }
    }
}
