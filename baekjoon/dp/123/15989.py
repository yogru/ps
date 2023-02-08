import sys

dp = [1] * 10001

for i in range(2, 10001):
    dp[i] += dp[i - 2]

for i in range(3, 10001):
    dp[i] += dp[i - 3]

for _ in range(int(sys.stdin.readline())):
    n = int(sys.stdin.readline())
    print(dp[n])
