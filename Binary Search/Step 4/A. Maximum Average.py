n, d  = map(int, input().split())
arr = list(map(int, input().split()))

def hasAvg(x):
    presum = [0] * (len(arr) + 1)
    for i in range(1, len(arr) + 1):
        presum[i] = presum[i-1] + (arr[i-1] - x)
    
    minpre = 0.0
    minpos = 0
    
    for r in range(d, len(arr) + 1):
        if presum[r-d] < minpre:
            minpre = presum[r-d]
            minpos = r-d
        
        if minpre <= presum[r]:
            return True, (minpos + 1, r)
        
    return False, (-1, -1)


l = -1
r = max(arr)

while r - l > 1e-5:
    m = (l+r)/2
    if hasAvg(m)[0]:
        l = m
    else:
        r = m

bl, br = hasAvg(l)[1]
print(bl, br)
