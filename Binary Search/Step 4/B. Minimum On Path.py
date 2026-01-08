from collections import deque

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]

r = -1
edges = []
for i in range(m):
    ai, bi, ci = map(int, input().split())
    edges.append((ai, bi, ci))
    r = max(r, ci)

def hasAvg(x):
    graph = [[] for _ in range(n+1)]

    for edge in edges:
        graph[edge[0]].append((edge[1], edge[2] - x))

    costs = [float('inf')] * (n+1)
    costs[1] = 0
    queue = deque([1])
    parent = [-1] * (n+1)

    while queue:
        curr = queue.popleft()

        if costs[curr] == float('inf'):
            continue

        for nei, neiw in graph[curr]:
            if costs[nei] > costs[curr] + neiw:
                costs[nei] = costs[curr] + neiw
                queue.append(nei)
                parent[nei] = curr

    if costs[n] <= 0:
        curr = n
        path = []
        while curr != -1:
            path.append(curr)
            curr = parent[curr]
        path.reverse()
        return path
    
    return []


l = -1

while r - l > 1e-6:
    mid = (r+l)/2
    if hasAvg(mid):
        r = mid
    else:
        l = mid
res = hasAvg(r)
print(len(res)-1)
print(*res)