#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, x, y;

bool f(ll t) {
    if (t < min(x, y)) return false;

    ll c = 1;
    t -= min(x, y);
    c += floor(t / x) + floor(t / y);
    return c >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x >> y;
    ll l = 0;
    ll r = max(x, y) * n;

    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << "\n";

    return 0;
}