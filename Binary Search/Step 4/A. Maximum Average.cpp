#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, d;
vector<ll> arr;

vector<ll> hasAvg(ld x) {
    vector<ld> presum(n+1);
    presum[0] = 0;
    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i-1] + (arr[i] - x);
    }

    ld minpre = 0.0;
    ll minpos = 0;

    for (ll r = d; r <= n; r++) {
        if (presum[r-d] < minpre) {
            minpre = presum[r-d];
            minpos = r-d;
        }
        
        if (presum[r] >= minpre) {
            return {minpos+1, r};
        }
    }
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;
    arr.resize(n+1);

    for(int i = 1; i<=n; i++) cin >> arr[i];

    ld l = 0;
    ld r = *max_element(arr.begin(), arr.end());
    vector<ll> res;
    while (r-l > 1e-6) {
        ld m = (r+l) / 2;
        res = hasAvg(m);
        if (res.size() > 0) {
            l = m;
        } else {
            r = m;
        }
    }

    res = hasAvg(l);
    cout << res[0] << " " << res[1];

    return 0;
}