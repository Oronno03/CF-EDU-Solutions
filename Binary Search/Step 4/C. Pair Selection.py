n, k = map(int, input().split())
pairs = []
r =  -1
for _ in range(n):
    ai, bi = map(int, input().split())
    pairs.append((ai, bi))
    r = max(r, ai/bi)

def hasRatio(x):
    vals = [0] * n
    for i in range(n):
        vals[i] = pairs[i][0] - (pairs[i][1]*x)

    vals.sort(reverse=True)

    return sum(vals[:k]) >= 0

l = 0

for i in range(100):
    m = (r+l)/2
    if hasRatio(m):
        l = m
    else:
        r = m

print(l)