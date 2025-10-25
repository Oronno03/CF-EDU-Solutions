#include <bits/stdc++.h>
using namespace std;

int closestToRight(vector<int> &arr, int target) {
    int l = -1;
    int r = arr.size();

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < target) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> queries(k);

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < k; i++) cin >> queries[i];

    for (auto query : queries) {
        cout << closestToRight(arr, query) << "\n";
    }
    return 0;

    return 0;
}