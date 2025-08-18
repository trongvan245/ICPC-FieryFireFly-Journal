// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 2e5 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

void xuly() {
    int n, c1, c2;
    cin >> n >> c1 >> c2;
    if (c1 * 2 <= c2) {
        cout << n * 3 * c1 << '\n';
        return;
    }
    
    c1 = min(c1, c2);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        sort(s.begin(), s.end());

        if (s[0] == s[1] || s[1] == s[2]) {
            ans += c1 + c2;
        }
        else ans += c1 * 3;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.