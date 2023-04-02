import math
import sys

N, M, K = tuple(map(int, sys.stdin.readline().split()))

r = [[-1] * (N + 1) for _ in range(N + 1)]

for _ in range(K):
    a, b, c = map(int, sys.stdin.readline().split())
    r[a][b] = max(r[a][b], c)

dp = [[-math.inf] * (M + 1) for _ in range(N + 1)]
ret = 0


def nap(item: int, weight: int):
    if item != N and weight == M:
        return -math.inf

    if item == N:
        return 0

    if dp[item][weight] != -math.inf:
        return dp[item][weight]

    for next_item in range(item + 1, N + 1):
        next_value = r[item][next_item]
        if next_value == -1:
            continue
        dp[item][weight] = max(dp[item][weight], next_value + nap(next_item, weight + 1))
    return dp[item][weight]


print(nap(1, 1))
