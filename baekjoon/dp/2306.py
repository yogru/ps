import math
import sys

koi = list(sys.stdin.readline().rstrip())
len_koi = len(koi)
dp = [[-1] * len_koi for _ in range(len_koi)]


def dfs(start, end):
    if dp[start][end] != -1:
        return dp[start][end]

    dp[start][end] = 0
    side_str = koi[start] + koi[end]
    if side_str == "at" or side_str == "gc":
        dp[start][end] = dfs(start + 1, end - 1) + 2

    for k in range(start, end):
        dp[start][end] = max(dp[start][end], dfs(start, k) + dfs(k + 1, end))

    return dp[start][end]


print(dfs(0, len_koi - 1))
