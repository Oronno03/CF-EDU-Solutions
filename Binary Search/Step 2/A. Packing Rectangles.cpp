#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long w, h, n;
    cin >> w >> h >> n;
    long long l = 0;
    long long r = max(w, h) * n;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if ((mid / w) * (mid / h) >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;

    return 0;
}