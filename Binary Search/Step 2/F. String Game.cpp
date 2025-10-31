#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> orders;

bool isIn(string s1, string s2) {
    int i = 0;
    for(char c: s1) {
        if (i < s2.size() && s2[i] == c) i++;
    }
    return i == (int)s2.size();
}

bool f(int n) {
    string curr = "";
    
    unordered_set<int> removable;
    for(int i =0; i < n; i++) {
        removable.insert(orders[i]);
    }

    for(int i = 0; i < t.size(); i++) {
        if(removable.find((i+1)) == removable.end()) {
            curr += t[i];
        }
    }

    return isIn(curr, p);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> p;
    orders.resize(t.size());
    for(int i=0; i < t.size(); i++) {
        cin >> orders[i];
    }

    long long l = 0;
    long long r = t.size();
    while(l+1<r) {
        auto m = (l+r)/2;
        if(f(m)) l = m;
        else r = m;
    }

    cout << l << "\n";

    return 0;
}