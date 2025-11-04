n, k = map(int, input().split())
a = list(map(int, input().split()))

def canForm(x):
    segments = 1
    curr = 0
    for i in range(n):
        if a[i] > x:
            return False
        
        if curr + a[i] > x:
            segments += 1
            curr = a[i]

        else:
            curr += a[i]

    return segments <= k

l = 0
r = sum(a)

while l + 1 < r:
    m = int((l+r)/2)
    if canForm(m):
        r = m 
    else:
        l = m

print(r)