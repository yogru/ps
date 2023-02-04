import sys

"""
 가장 긴 부분 증가 수열을 최대한 유지 하면서
 나머지를 움직이는게 효율이 좋다. 
 
 3 7 5 2 6 1 4
 -> 최장 부분 증가 수열: [1, 2, 2, 1, 3, 1, 2]
    즉 3,5,6은 유지 하면서 나머지 7,2,1,4를 오름 차순 순으로 넣어 주면 그게 최소 값이다.
"""

N = int(sys.stdin.readline())
R = [int(sys.stdin.readline()) for _ in range(N)]
dp = [0] * N

for i in range(N):
    for j in range(i):
        if R[j] < R[i]:
            dp[i] = max(dp[i], dp[j])
    dp[i] += 1

print(N - max(dp))
