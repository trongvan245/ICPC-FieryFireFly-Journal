toanga.cpp

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; ++i) {
        string s = to_string(i);
        string origin = s;
        do {
            char lst = s.back();
            s.pop_back();
            s = lst + s;
            if (s[0] == '0') {
                continue;
            }
            int k = stoi(s);
            if (k > i && k <= b) {
                ans++;
            }
        } while (s != origin);
    }
    ee de a tien code kia
    // ua sao chay lau v ta
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