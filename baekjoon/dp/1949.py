import sys

sys.setrecursionlimit(10 ** 5)

N = int(sys.stdin.readline())
A = [0] + list(map(int, sys.stdin.readline().split()))
adj = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    a, b = tuple(map(int, sys.stdin.readline().split()))
    adj[a].append(b)
    adj[b].append(a)

dp = [[0, A[i]] for i in range(N + 1)]
visit = [False] * (N + 1)


def dfs(v):
    visit[v] = True
    for u in adj[v]:
        if not visit[u]:
            dfs(u)
            dp[v][1] += dp[u][0]
            dp[v][0] += max(dp[u][0], dp[u][1])


dfs(1)
print(max(dp[1]))

"""
6
10 1 1 1 10 10
1 2
2 3
3 4
4 5
3 6

7
100 1 1 100 1 1 100
1 2
2 3
3 4
3 5
5 6
6 7
"""
