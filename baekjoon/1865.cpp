#include <iostream>
#include <vector>
#include <climits>


using namespace std;

#define MAX 987654321

struct Edge {
    int s, e, t;
};

vector<Edge> edges;
vector<int> dist;

int n, m, w;

void input() {
    edges.clear();
    dist.clear();
    cin >> n >> m >> w;

    for (int i = 0; i <= n; i++) dist.push_back(MAX);

    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s, e, t});
        edges.push_back({e, s, t});
    }
    for (int i = 0; i < w; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        edges.push_back({s, e, -t});
    }
}


bool bellmanFord(int start) {
    dist[start] = 0;
    int s, e, t;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < edges.size(); j++) {
            s = edges[j].s;
            e = edges[j].e;
            t = edges[j].t;
            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
            }
        }
    }

    for (int j = 0; j < edges.size(); j++) {
        s = edges[j].s;
        e = edges[j].e;
        t = edges[j].t;
        if (dist[e] > dist[s] + t) {
            return true;
        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        input();
        if (bellmanFord(1)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}