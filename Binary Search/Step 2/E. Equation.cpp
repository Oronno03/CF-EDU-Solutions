#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long double c;
    cin >> c;
    long double l = -1;
    long double r = 1e10;
    for(int i = 0;  i < 100; i++) {
        long double m = (l+r)/2;
        long double v = pow(m, 2) + sqrt(m);
        if(fabs(v - c) <= 1e-6) {
            cout << fixed << setprecision(20) << m << "\n";
            return 0;
        } 
        if (v > c) r = m;
        else l = m;
    }

    cout << fixed << setprecision(20) << r << "\n";

    return 0;
}