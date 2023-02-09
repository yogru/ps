import sys

N = int(sys.stdin.readline())
R = list(map(int, sys.stdin.readline().split()))

dp = [0, abs(R[0] - R[1])]

for i in range(2, N):
    max_value = R[i]
    min_value = R[i]
    result = 0
    for j in range(i, 0, -1):
        max_value = max(max_value, R[j])
        min_value = min(min_value, R[j])
        result = max(result, abs(max_value - min_value) + dp[j - 1])

    dp.append(result)

# print(dp)
print(max(dp))
