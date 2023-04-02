import sys

n = int(sys.stdin.readline())
a, b = tuple(map(int, sys.stdin.readline().split()))
c = int(sys.stdin.readline())
t = [0] + [int(sys.stdin.readline()) for _ in range(c)]

dp = [[[-1] * (n + 1) for _ in range(n + 1)] for __ in range(c + 1)]

"""
    굉장히 DP 정석적인 문제. 
"""


def go_open(depth: int, x1: int, y1: int):
    if depth > c:
        return 0
    x = min(x1, y1)
    y = max(x1, y1)
    # print(depth, x, y)
    if dp[depth][x][y] != -1:
        return dp[depth][x][y]
    target = t[depth]
    dp[depth][x][y] = min(abs(x - target) + go_open(depth + 1, target, y),
                          abs(y - target) + go_open(depth + 1, target, x)
                          )
    return dp[depth][x][y]


go_open(1, a, b)
print(dp[1][a][b])
