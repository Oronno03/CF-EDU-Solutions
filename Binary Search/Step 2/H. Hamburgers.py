burger = input()
counts = [burger.count(i) for i in "BSC"]
kitchen = list(map(int, input().split()) )
shop = list(map(int, input().split()) )
m = int(input())

# 0 -> burger
# 1 -> sausage
# 2 -> cheese


def canMakeBurgers(x):
    req = [counts[i]*x for i in range(3)]
    diff = [max(req[i]-kitchen[i], 0) for i in range(3)]
    if sum(diff[i] * shop[i] for i in range(3)) > m:
        return False
    return True

l = 0
r = 1e13

while l + 1 < r:
    mid = int((l+r)//2)
    if canMakeBurgers(mid):
        l = mid
    else:
        r = mid

print(l)
