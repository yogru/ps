import sys

a = list(sys.stdin.readline().rstrip())
b = list(sys.stdin.readline().rstrip())

dp = [[0] * (len(b) + 1) for _ in range(len(a) + 1)]
ret = 0
for r in range(1, len(a) + 1):
    for c in range(1, len(b) + 1):
        if a[r - 1] == b[c - 1]:
            dp[r][c] = dp[r - 1][c - 1] + 1
            ret = max(ret, dp[r][c])

print(ret)
