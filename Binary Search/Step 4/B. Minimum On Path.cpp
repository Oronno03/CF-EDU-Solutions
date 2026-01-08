#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

ld n, m;
vector <vector<ll>> edges;

vector<ll> hasAvg(ld x) {

    vector<vector<pair<ll, ld>>> graph(n+1);
    for(vector<ll> edge: edges) {
        graph[edge[0]].push_back({edge[1], edge[2]-x});
    }

    vector<ld> costs(n+1, 1e18L);
    vector<ll> parents(n+1, -1);
    vector<bool> inqueue(n+1, false);
    costs[1] = 0;
    inqueue[1] = true;
    deque<ll> queue;
    queue.push_back(1);

    while (!queue.empty()) {
        ll curr = queue.front();
        queue.pop_front();
        inqueue[curr] = false;

        if (costs[curr] >= 1e18l) continue;

        for (auto nei: graph[curr]) {
            if (costs[nei.first] > costs[curr] + nei.second) {
                costs[nei.first] = costs[curr] + nei.second;
                if (!inqueue[nei.first]){
                    queue.push_back(nei.first);
                    inqueue[nei.first] = true;
                }
                parents[nei.first] = curr;
            }
        }
    }

    if (costs[n] <= 0) {
        ll curr = n;
        vector<ll> path;
        while (curr != -1) {
            path.push_back(curr);
            curr = parents[curr];
        }
        reverse(path.begin(), path.end());
        return path;
    }

    return {};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    edges.resize(m);
    ld r = -1;
    for (int i = 0; i < m; i++) {
        vector<ll> edge(3);
        cin >> edge[0] >> edge[1] >> edge[2];
        edges[i] = edge;
        r = max((ld)edge[2], r);
    }

    ld l = -1;
    for(int i = 0; i < 50; i++) {
        ld mid = (r+l)/2;
        if (hasAvg(mid).size() > 0) r = mid;
        else l = mid;
    }

    vector<ll> res = hasAvg(r);
    cout << res.size() - 1 << "\n";
    for (auto i: res) {
        cout << i << " ";
    }

    return 0;
}