m, n = map(int, input().split())
t = []
z = []
y = []
for i in range(n):
    ti, zi, yi = map(int, input().split())
    t.append(ti)
    z.append(zi)
    y.append(yi)


def f(x):
    count = 0
    for i in range(n):
        count += maxBalloons(i, x)
    return count >= m

def maxBalloons(i, time):
    oneSetTime = (t[i] * z[i]) + y[i]
    totalSets = time//oneSetTime
    timeRemains = time % oneSetTime
    balloons = 0
    balloons += totalSets * z[i]
    balloons += min(timeRemains//t[i], z[i])
    return balloons

l = 0
r = 10 ** 9

if m == 0:
    print(0)
    print(*([0]*n))
    exit()

while l + 1 < r:
    mid = (l + r) // 2
    if f(mid):
        r = mid
    else:
        l = mid

print(r)
counts = [maxBalloons(i, r) for i in range(n)]
total = sum(counts)

if total > m:
    for i in range(n):
        while total > m and counts[i] > 0:
            total -= 1
            counts[i] -= 1

print(*counts)