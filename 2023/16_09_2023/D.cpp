#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int &i : b) {
        cin >> i;
    }
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int x;
            cin >> x;
            x--;
            mn = min(mn, a[i] + b[x]);
        }
    }

    int cost;
    cin >> cost;
    cout << max(0, cost / mn - 1);
}