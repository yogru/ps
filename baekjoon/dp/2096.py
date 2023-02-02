import sys

N = int(sys.stdin.readline())
MAP = [list(map(int, sys.stdin.readline().split(" "))) for _ in range(N)]

pre_max_dp = [MAP[0][0], MAP[0][1], MAP[0][2]]
pre_min_dp = [MAP[0][0], MAP[0][1], MAP[0][2]]

for r in range(1, N):
    current_max_dp = [MAP[r][0], MAP[r][1], MAP[r][2]]
    current_min_dp = [MAP[r][0], MAP[r][1], MAP[r][2]]
    for c in range(3):
        if c == 0:
            current_max_dp[c] += max(pre_max_dp[c], pre_max_dp[c + 1])
            current_min_dp[c] += min(pre_min_dp[c], pre_min_dp[c + 1])
        elif c == 2:
            current_max_dp[c] += max(pre_max_dp[c], pre_max_dp[c - 1])
            current_min_dp[c] += min(pre_min_dp[c], pre_min_dp[c - 1])
        else:
            current_max_dp[c] += max(pre_max_dp[c], pre_max_dp[c - 1], pre_max_dp[c + 1])
            current_min_dp[c] += min(pre_min_dp[c], pre_min_dp[c - 1], pre_min_dp[c + 1])
    pre_max_dp = current_max_dp
    pre_min_dp = current_min_dp

print(max(pre_max_dp), min(pre_min_dp))

# 아래 방식으로 풀면 메모리 초과
# max_dp = [[0] * 3 for _ in range(N)]
# min_dp = [[0] * 3 for _ in range(N)]
#
# min_dp[0][0] = max_dp[0][0] = MAP[0][0]
# min_dp[0][1] = max_dp[0][1] = MAP[0][1]
# min_dp[0][2] = max_dp[0][2] = MAP[0][2]
#
# for r in range(1, N):
#     for c in range(3):
#         if c == 0:
#             max_dp[r][c] = max(max_dp[r - 1][c], max_dp[r - 1][c + 1])
#             min_dp[r][c] = min(min_dp[r - 1][c], min_dp[r - 1][c + 1])
#         elif c == 2:
#             max_dp[r][c] = max(max_dp[r - 1][c - 1], max_dp[r - 1][c])
#             min_dp[r][c] = min(min_dp[r - 1][c - 1], min_dp[r - 1][c])
#         else:
#             max_dp[r][c] = max(max_dp[r - 1][c - 1], max_dp[r - 1][c], max_dp[r - 1][c + 1])
#             min_dp[r][c] = min(min_dp[r - 1][c - 1], min_dp[r - 1][c], min_dp[r - 1][c + 1])
#         max_dp[r][c] += MAP[r][c]
#         min_dp[r][c] += MAP[r][c]
#
# print(max(max_dp[N - 1]), min(min_dp[N - 1]))
