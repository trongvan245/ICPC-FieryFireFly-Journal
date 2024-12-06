#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("G.inp", "r")) {
        freopen("G.inp", "r", stdin);
        freopen("G.ans", "w", stdout);
    }

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    long long ans = 1e18;
    for (int i = 0; i < n; ++i) {
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            res += min(abs(a[j] - a[i]), abs(a[j]));
        }
        ans = min(ans, res);
    }

    cout << ans;
}