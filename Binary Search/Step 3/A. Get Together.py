x = []
v = []

for _ in range(int(input())):
    xi, vi = map(int, input().split())
    x.append(xi)
    v.append(vi)

def canCome(t):
    maxL = -float('inf')
    minR = float('inf')
    for i in range(len(x)):
        can = t*v[i]
        left = x[i] - can
        right = x[i] + can
        maxL = max(left, maxL)
        minR = min(right, minR)

    # print(maxL, minR)
    return maxL <= minR 

l = 0 
r = 1e13

for _ in range(100):
    mid = (l+r)/2
    if canCome(mid):
        r = mid
    else:
        l = mid

print(r)