n, k = map(int, input().split())
stalls = list(map(int, input().split()))

def canBePlaced(x):
    placed = 1
    last = 0
    for i in range(1, n):
        if stalls[i] - stalls[last] >= x:
            placed += 1
            last = i
    return placed >= k


l = 0
r = max(stalls)

while l + 1 < r:
    mid = int(l/2+r/2)
    if canBePlaced(mid):
        l = mid
    else:
        r = mid

print(l)