import sys

# 대각선이동이라는게 단순 증가만 아니라. 방향 조절까지

X, Y, W, S = tuple(map(int, sys.stdin.readline().split()))
case1 = W * (X + Y)
case2 = min(X, Y) * S + abs(X - Y) * W
case3 = max(X, Y) * S if (X + Y) % 2 == 0 else (max(X, Y) - 1) * S + W
print(min(case1, case2, case3))
