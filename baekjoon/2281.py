import sys

input = sys.stdin.readline
n, m = map(int, input().split())
words = [int(input()) for _ in range(n)]
dp = [[-1 for i in range(m)] for j in range(n)]


def dfs(idx, tmp):
    if idx == n - 1:
        return 0
    if dp[idx][tmp] != -1:
        return dp[idx][tmp]

    if tmp + 1 + words[idx + 1] < m:
        dp[idx][tmp] = min(dfs(idx + 1, tmp + 1 + words[idx + 1]),
                           dfs(idx + 1, words[idx + 1] - 1) + (m - tmp - 1) * (m - tmp - 1))
    else:
        dp[idx][tmp] = dfs(idx + 1, words[idx + 1] - 1) + (m - tmp - 1) * (m - tmp - 1)
    return dp[idx][tmp]


print(dfs(0, words[0] - 1))
