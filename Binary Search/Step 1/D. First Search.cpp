#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int sl, int sr) {
    // Find the max index where Ai < sl
    int lowerBound = 0;
    int l = -1;
    int r = arr.size();
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < sl) {
            l = mid;
        } else {
            r = mid;
        }
    }
    lowerBound = l;

    // Find the max index where Ai <= sr
    int upperBound = 0;
    l = -1;
    r = arr.size();
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (arr[mid] <= sr) {
            l = mid;
        } else {
            r = mid;
        }
    }
    upperBound = l;
    return (upperBound - lowerBound);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << search(arr, l, r) << " ";
    }

    return 0;
}