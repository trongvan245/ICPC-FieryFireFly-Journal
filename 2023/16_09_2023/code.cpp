#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;

    for (int i = a; i <= b; ++i) {
        int mu = 1, temp = i;
        while (temp >= 10) {
            mu *= 10;
            temp /= 10;
        }
        int tmp = i;
        int cnt = 0;
        while (true) {
            cnt++;
            tmp = tmp / 10 + (tmp % 10) * mu;
            if (tmp == i) {
                break;
            }
            if (i < tmp && tmp <= b) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}