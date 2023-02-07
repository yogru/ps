import sys

N = int(sys.stdin.readline())
dp = [0 for _ in range(1000001)]

dp[1] = 1
dp[2] = 2

for c in range(3, N + 1):
    if c % 2 == 0:
        dp[c] = (dp[c - 1] + dp[c // 2]) % 1000000000
    else:
        dp[c] = dp[c - 1]
    dp[c] %= 1000000000

print(dp[N])
