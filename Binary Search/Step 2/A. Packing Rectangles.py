w, h, n = map(int, input().split())

l = 0
r = max(w, h) * n

while l + 1 < r:
    mid = (l + r) // 2
    poss = (mid // w) * (mid // h)
    if poss >= n:
        r = mid
    else:
        l = mid

print(r)
