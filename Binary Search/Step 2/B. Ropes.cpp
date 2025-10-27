#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ropes;

bool f(double x) {
    int total = 0;
    for (auto rope : ropes) {
        total += floor(rope / x);
    }
    return total >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    ropes.resize(n);
    for (int i = 0; i < n; i++) cin >> ropes[i];

    double l = 0;
    double r = 1e8;

    for (int t = 0; t < 100; t++) {
        double m = (l + r) / 2;
        if (f(m))
            l = m;
        else
            r = m;
    }

    cout << setprecision(20) << l << "\n";

    return 0;
}