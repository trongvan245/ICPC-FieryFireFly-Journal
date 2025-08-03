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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        int res = 1e9;
        for (int i = k, j = 1; i <= n; ++i, ++j)
            res = min(res, abs(a[i] - b[j]));

        for (int i = 1, j = n - k + 2; i < k; ++i, ++j)
            res = min(res, abs(a[i] - b[j]));

        ans = max(ans, res);

        // cout << k << " " << res << '\n';
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
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.