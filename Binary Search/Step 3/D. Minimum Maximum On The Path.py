from collections import deque

n, m, d = map(int, input().split())

graph = {n: [] for n in range(1, n+1)}
r = -1

for _ in range(m):
    ai, bi, ci = map(int, input().split())
    graph[ai].append((bi, ci))
    r = max(r, ci)


def canGo(x):
    queue = deque([1])
    parent = [-1] * (n+1)
    distance = [float('inf')] * (n+1)
    distance[1] = 0

    while queue:
        curr = queue.popleft()

        if distance[curr] >= d:
            continue

        for nei, neiw in graph[curr]:
            if neiw > x:
                continue
            if distance[nei] > distance[curr] + 1:
                distance[nei] = distance[curr] + 1
                parent[nei] = curr
                queue.append(nei)
    
    if distance[n] <= d:
        path = []
        curr = n
        while curr != -1:
            path.append(curr)
            curr = parent[curr]
        return path[::-1]

        
    return None
    
l = -1

while l + 1 < r:
    m = int((l+r)/2)
    if canGo(m):
        r = m
    else:
        l = m


if res := canGo(r):
    print(len(res) - 1)
    print(*res)
else:
    print(-1)
