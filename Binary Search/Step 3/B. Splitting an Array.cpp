#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, k;
vector<ll> arr;


bool canForm(ll x) {
    ll segments = 1;
    ll curr = 0;
    for (int i=0; i < n; i++) {
        if (arr[i] > x) return false;
        if (arr[i] + curr > x) {
            segments += 1;
            curr = arr[i];
        } else {
            curr += arr[i];
        }
    }
    return segments <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    arr.resize(n);

    for (int i=0; i < n; i++) cin >> arr[i];

    ll l = 0;
    ll r = accumulate(arr.begin(), arr.end(), 0LL);

    while (l + 1 < r) {
        ll m = (l+r) / 2;
        if (canForm(m)) r = m;
        else l = m;
    }

    cout << r << "\n";

    return 0;
}