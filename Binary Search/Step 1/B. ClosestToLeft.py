n, k = map(int, input().split())
arr = list(map(int, input().split()))
queries = list(map(int, input().split()))


# UpperBound
def closestToLeft(arr, target):

    l = -1
    r = len(arr)

    while l + 1 < r:
        mid = (l + r) // 2
        if arr[mid] <= target:
            l = mid
        else:
            r = mid
    return r


for query in queries:
    print(closestToLeft(arr, query))
