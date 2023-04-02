import sys

t = int(sys.stdin.readline())

dp = [1, 2, 4]
v = 1000000009

for _ in range(t):
    n = int(sys.stdin.readline())
    if len(dp) < n:
        for i in range(len(dp) - 1, n):
            dp.append((dp[i] % v + dp[i - 1] % v + dp[i - 2] % v) % v)
    print((dp[n - 1]))

