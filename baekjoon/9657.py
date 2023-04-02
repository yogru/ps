import sys

N = int(sys.stdin.readline())

dp = [0, 1, 0, 1, 1]

for i in range(5, N + 1):
    if dp[i - 1] == 1 and dp[i - 3] == 1 and dp[i - 4] == 1:
        dp.append(0)
    else:
        dp.append(1)

if dp[N] == 0:
    print("CY")
else:
    print("SK")
