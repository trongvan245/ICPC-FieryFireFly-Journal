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

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

struct four {
    int u, v, x, y;
};
four a[25], b[25];

int n, m, k;

ll get() {
    ll ans = 0;
    for (int resy = 0; resy <= m; ++resy) {
        vector<pii> M;
        for (int i = 1; i <= k; ++i)
            if (a[i].v <= resy && resy <= a[i].y) {
                M.pb({a[i].u, 1});
                M.pb({a[i].x, -1});
            }

        sort(M.begin(), M.end());
        int c = 0, pre = M[0].fi;

        int p = 0;
        while (p < M.size()) {
            pii e = M[p];
            int l = p;

            while (l + 1 < M.size() && e == M[l + 1])
                ++l;

            int n1 = 0, n2 = 0;
            for (int j = p; j <= l; ++j)
                if (M[j].se == 1)
                    ++n1;
                else
                    ++n2;

            c += n1;
            if (c % 2) {
                if (pre != -1)
                    ++ans, pre = e.fi;
                else
                    ans += e.fi - pre, pre = e.fi;
            } else
                pre = -1;
            cout << p << " " << e.fi << " " << ans << " " << c << '\n';
            c -= n2;
            p = l + 1;
        }

        cout << resy << " " << ans << '\n';
        cout << '\n';
    }
    return ans;
}

ll findmin() {
    int resx, resy;
    for (resy = 0; resy <= m; ++resy) {
        vector<pii> M;
        for (int i = 1; i <= k; ++i)
            if (a[i].v <= resy && resy <= a[i].y) {
                M.pb({a[i].u, 1});
                M.pb({a[i].x + 1, -1});
            }

        sort(M.begin(), M.end());
        int c = 0;
        for (int i = 0; i < M.size(); ++i) {
            pii e = M[i];
            c += e.se;

            if (i + 1 == M.size() || M[i + 1].fi != e.fi) {
                if (c % 2) {
                    return 1ll * resy * (n + 1) + e.fi;
                }
            }
        }
    }
    return -123;
}

ll findmax() {
    int resx, resy;
    for (resy = m; resy >= 0; --resy) {
        vector<pii> M;
        for (int i = 1; i <= k; ++i)
            if (a[i].v <= resy && resy <= a[i].y) {
                M.pb({a[i].u - 1, -1});
                M.pb({a[i].x, 1});
            }

        sort(M.begin(), M.end(), greater<pii>());
        int c = 0;
        for (int i = 0; i < M.size(); ++i) {
            pii e = M[i];
            c += e.se;

            if (i + 1 == M.size() || M[i + 1].fi != e.fi) {
                if (c % 2) {
                    return 1ll * resy * (n + 1) + e.fi;
                }
            }
        }
    }
    return -123;
}

void xuly() {
    cin >> n >> m >> k;
    // clock_t bt = clock();
    for (int i = 1; i <= k; ++i) {
        // cin >> a[i].v >> a[i].u >> a[i].y >> a[i].x;
        cin >> a[i].u >> a[i].v >> a[i].x >> a[i].y;
        a[i].x += a[i].u;
        a[i].y += a[i].v;
        b[i] = a[i];
        // cout << a[i].u << " " << a[i].v << " " << a[i].x << " " << a[i].y
        //      << '\n';
    }
    // cout << '\n';
    ll ans1 = get();

    if (ans1 == 0) {
        cout << 0 << " " << -1 << " " << -1;
        return;
    }
    ll ans2 = findmin();
    ll ans3 = findmax();

    cout << ans1 << " " << ans2 << " " << ans3;
    cout << '\n';
    // clock_t et = clock();

    // cout << (et - bt) / CLOCKS_PER_SEC << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    xuly();
}

// Surely nothing could go wrong.