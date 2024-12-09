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

const int N = 5005;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

pii a[N];
void xuly() {
    int n, A, B;
    cin >> n >> A >> B;
    vector<vector<int>> card(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a + 1, a + 1 + n);

    int top = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].fi != a[i - 1].fi)
            ++top;
        card[top].pb(a[i].se);
    }


    vector<vector<int>> d(top + 1);
    for (int suit = 1; suit <= top; ++suit) {
        vector<int> &e = card[suit];

        int p = 0;
        d[suit].assign((int)e.size() + 1, 1e9);
        for (int i = 0; i <= n; ++i) {
            while (p != e.size() && e[p] <= 2 * (p + 1 + i) - 1)
                ++p;
            d[suit][(int)e.size() - p] = min(d[suit][(int)e.size() - p], i);
        }

    }
    // cout << '\n';
    int sz = 0;
    vector<int> dp(5005, n), pre(5005, 0);

    for (int suit = 1; suit <= top; ++suit) {
        vector<int> &e = d[suit];

        for (int i = 0; i <= sz; ++i)
            for (int j = 0; j < e.size(); ++j) {
                dp[i + j] = min(dp[i + j], pre[i] + e[j]);
            }

        sz += (int)e.size() - 1;

        for (int i = 0; i <= sz; ++i) {
            pre[i] = dp[i];
            dp[i] = n;
        }
    }
    assert(sz == n);

    int ans = n;
    for (int i = 0; i <= sz; ++i)
        ans = min(ans, max(i, pre[i]));
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