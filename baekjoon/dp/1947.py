import sys

N = int(sys.stdin.readline())
dp = [0, 0, 1, 2, 9]
div = 1000000000
for n in range(5, N + 1):
    next_val = dp[n - 1] * (n - 1) % 1000000000 + (n - 1) * dp[n - 2] % 1000000000
    dp.append(next_val % div)

print(dp[N])
