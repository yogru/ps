import sys

N, S, R = tuple(map(int, sys.stdin.readline().split()))
A = [1] * N

for i in list(map(int, sys.stdin.readline().split())):
    A[i - 1] -= 1

for i in list(map(int, sys.stdin.readline().split())):
    A[i - 1] += 1

for i in range(len(A)):
    if A[i] == 0:
        if i - 1 >= 0 and A[i - 1] >= 2:
            A[i] = 1
            A[i - 1] -= 1
        elif i + 1 < len(A) and A[i + 1] >= 2:
            A[i] = 1
            A[i + 1] -= 1

ret = 0
for i in range(len(A)):
    if A[i] == 0:
        ret += 1
print(ret)
