#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

ll n;
vector<ll> pos;
vector<ll> speed;

bool canCome(ld t) {
    ld maxLeft = INT64_MIN;
    ld minRight = INT64_MAX;

    for (ll i = 0; i < n; i++) {
        ld range = t * speed[i];
        ld left = pos[i] - range;
        ld right = pos[i] + range;
        maxLeft = max(left, maxLeft);
        minRight = min(right, minRight);
    }
    
    return maxLeft <= minRight;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; i++) {
        ll posi, speedi;
        cin >> posi >> speedi;
        pos.push_back(posi);
        speed.push_back(speedi);
    }

    ld l = 0;
    ld r = 1e13; 

    for(int i=0; i < 100; i++) {
        ld m = (l+r)/2;
        if (canCome(m)) r = m;
        else l = m;
    }

    cout << setprecision(20) << r << "\n";

    return 0;
}