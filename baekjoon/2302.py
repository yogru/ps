import sys

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
vips = [int(sys.stdin.readline()) for _ in range(M)]

dp = [0] * 41
dp[0] = 1
dp[1] = 1
dp[2] = 2

for i in range(3, 41):
    dp[i] = dp[i - 1] + dp[i - 2]

ret = 1
if M >= 1:
    tmp = 0
    for i in range(M):
        ret *= dp[vips[i] - tmp - 1]
        tmp = vips[i]
    ret *= dp[N - tmp]
else:
    ret = dp[N]

print(ret)

# 맨 처음 백트래킹 시도
# MAP = [False] * N
#
# for _ in range(M):
#     a = int(sys.stdin.readline())
#     MAP[a - 1] = True
#
# count = 0
# def bt(i, arr):
#     global count
#     if i == N:
#         count += 1
#         return
#
#     if MAP[i]:
#         arr[i] = True
#         bt(i + 1, arr)
#         return
#
#     for plus in [-1, 0, 1]:
#         if 0 <= i + plus < N:
#             if not arr[i + plus]:
#                 arr[i + plus] = True
#                 bt(i + 1, arr)
#                 arr[i + plus] = False
#
#
# bt(0, [False] * N)
