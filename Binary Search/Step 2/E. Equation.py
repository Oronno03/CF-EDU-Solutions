c = float(input())

l = -1
r = 1e10

for _ in range(100):
    m = (l + r) / 2
    v = m ** 2 + m**(1/2)
    if (abs(v-c) <= 1e-6):
        print(m)
        quit()
    elif v > c:
        r = m
    else:
        l = m

print(r)