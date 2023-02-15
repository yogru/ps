import sys

N = int(sys.stdin.readline())
dp = [1, 0, 1]

for c in range(3, N):
    if dp[c - 1] == 1 and dp[c - 3] == 1:
        dp.append(0)
    else:
        dp.append(1)

if dp[N - 1] == 1:
    print("SK")
else:
    print("CY")
