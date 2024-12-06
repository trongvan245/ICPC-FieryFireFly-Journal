#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ld sol(ld a, ld b, ld c) {
    ld cdenta = pow((pow(b, 2) - 4 * a * c), 0.5);
    if (a == 0.0) {
        return -1.0 * c / b;
    }
    return (-b + cdenta) / (2 * a);
}
void solve() {
    ld x, y;
    cin >> x >> y;
    ld a = sol(4 * y - 4 * x, 4 * x, -1 * y);
    cout << pow((a * x + (0.5 - a) * y), 3) / (27 * a * (0.5 - a)) << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    // xong roi anh
    int t;
    // ctrl + alt + N
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}