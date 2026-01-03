#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, m, d;
vector<vector<pair<ll, ll>>> graph;

vector<ll> canGo(ll x) {
    deque<ll> queue;
    queue.push_back(1);
    vector<ll> distance(n + 1, INTMAX_MAX);
    vector<ll> parent(n + 1, -1);
    distance[1] = 0;

    while (!queue.empty()) {
        ll curr = queue.front();
        queue.pop_front();

        if (distance[curr] >= d) {
            continue;
        }

        for (auto nei : graph[curr]) {
            if (nei.second > x) {
                continue;
            }
            if (distance[nei.first] > distance[curr] + 1) {
                distance[nei.first] = distance[curr] + 1;
                queue.push_back(nei.first);
                parent[nei.first] = curr;
            }
        }
    }

    if (distance[n] <= d) {
        ll curr = n;
        vector<ll> path;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        return path;
    }

    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;
    graph.resize(n + 1);
    ll r = -1;

    for (int i = 0; i < m; i++) {
        ll ai, bi, ci;
        cin >> ai >> bi >> ci;
        r = max(r, ci);
        graph[ai].push_back({bi, ci});
    }

    ll l = -1;

    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (canGo(mid).size() > 0)
            r = mid;
        else
            l = mid ;
    }

    auto path = canGo(r);
    if (path.size() > 0) {
        cout << path.size() - 1 << "\n";
        for (auto pathNode : path) {
            cout << pathNode << " ";
        }
    } else {
        cout << -1 << "\n";
    }
    return 0;
}