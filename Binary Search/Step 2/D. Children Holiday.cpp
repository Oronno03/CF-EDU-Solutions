    #include <bits/stdc++.h>
    using namespace std;

    vector<long long> t, z, y;
    // Ti -> Time taken to inflate 1 balloon
    // Zi -> How many balloons can be inflated before rest
    // Yi -> Time of rest
    long long m, n;
    // m -> Number of balloons
    // n -> Number of assistants

    long long g(long long x, long long i) {
        long long oneSetTime = t[i] * z[i] + y[i];
        long long totalSets = x / oneSetTime;
        long long balloons = totalSets * z[i];
        long long timeRemains = x % oneSetTime;
        balloons += min(timeRemains / t[i], z[i]);
        return balloons;
    }

    bool f(long long x) {
        long long c = 0;
        for (long long i = 0; i < n; i++) {
            c += g(x, i);
        }
        return c >= m;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> m >> n;
        t.resize(n);
        z.resize(n);
        y.resize(n);

        for (long long i = 0; i < n; i++) {
            cin >> t[i] >> z[i] >> y[i];
        }

        long long l = 0;
        long long r = 1e9;

        if (m == 0) {
            cout << 0 << "\n";
            for (long long i = 0; i < n; i++) {
                cout << 0 << " ";
            }
            cout << "\n";
            return 0;
        }

        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << r << "\n";
        vector<long long> counts(n);
        long long total = 0;
        for (long long i = 0; i < n; i++) {
            long long count =  g(r, i);
            counts[i] = count;
            total += count;
        }
        if (total > m) {
            for (long long i = 0; i < n; i++) {
                while (total > m && counts[i] > 0) {
                    total -=  1;
                    counts[i] -= 1;
                }
            }
        }
        for (long long i = 0; i < n; i++) {
            cout << counts[i] << " ";
        }
        cout << "\n";
        return 0;
    }