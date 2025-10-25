#include <iostream>
#include <vector>
using namespace std;

int bS(vector<int> &arr, int x) {
    int l = 0;
    int r = arr.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++) {
        int q;
        cin >> q;
        if (bS(arr, q) != -1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}