#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, k;
vector<ll> stalls;

bool canPlace(ll x) {
    ll placed = 1;
    ll last = 0;
    
    for(int i = 1; i < n; i++) {
        if (stalls[i] - stalls[last] >= x) {
            placed += 1;
            last = i;
        }
    }
    return placed >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    stalls.resize(n);
    for(int i = 0; i < n; i++) cin >> stalls[i];

    ll l = 0;
    ll r = *max_element(stalls.begin(), stalls.end());

    while (l+1 < r) {
        ll m = (l+r)/2;
        if (canPlace(m)) l = m;
        else r = m;
    }

    cout << l << "\n";

    return 0;
}