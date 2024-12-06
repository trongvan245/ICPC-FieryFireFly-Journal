#include <bits/stdc++.h>

using namespace std;

struct rect {
    int x, y, u, v;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen("K.inp", "r")) {
        freopen("K.inp", "r", stdin);
        freopen("K.out", "w", stdout);
    }

    int n;
    cin >> n;
    vector<rect> a(n);
    vector<int> X, Y;
    for (rect& i : a) {
        cin >> i.x >> i.y >> i.u >> i.v;
        X.push_back(i.x);
        X.push_back(i.u);
        Y.push_back(i.y);
        Y.push_back(i.v);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for (rect& i : a) {
        i.x = lower_bound(X.begin(), X.end(), i.x) - X.begin() + 1;
        i.u = lower_bound(X.begin(), X.end(), i.u) - X.begin() + 1;
        i.y = lower_bound(Y.begin(), Y.end(), i.y) - Y.begin() + 1;
        i.v = lower_bound(Y.begin(), Y.end(), i.v) - Y.begin() + 1;
    }

    for (auto [x, y, u, v] : a) {
    }
}