import sys

N = int(sys.stdin.readline())
K = int(sys.stdin.readline())
sensors = list(map(int, sys.stdin.readline().split()))
sensors.sort()

if K >= N:
    print(0)
else:
    diff = []
    for i in range(len(sensors) - 1):
        diff.append(sensors[i + 1] - sensors[i])
    diff.sort(reverse=True)
    print(sum(diff[K - 1:]))
