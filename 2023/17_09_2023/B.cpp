#include <bits/stdc++.h>

#define mp make_pair
#define pii pair<long long, int>
#define ll long long
#define fi first
#define se second

using namespace std;
constexpr int N = 5e5 + 5;
constexpr long long inf = 1e18;

int LG[N];
int a[N];
string s;
int n, k;
long long f[N], g[N];
long long rmqf[N][20], rmqg[N][20];

void buildRMQ(long long rmq[N][20], long long f[]) {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j < 20; ++j) {
            rmq[i][j] = inf;
        }
    }

    for (int i = 0; i <= n + 1; ++i) {
        rmq[i][0] = f[i];
    }

    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i <= n - (1 << j) + 2; ++i) {
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
}
long long getRMQ(long long rmq[N][20], int l, int r) {
    if (l > r) {
        return inf;
    }
    int k = LG[r - l + 1];
    return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    a[n + 1] = 0;
    cin >> s;
    s = "0" + s + "0";

    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '1') {
            tot += a[i];
        }
    }

    for (int i = 0; i <= n + 1; ++i) {
        f[i] = g[i] = inf;
    }

    f[0] = 0;
    deque<pii> q;

    q.emplace_back(0, 0);

    for (int i = 1; i <= n + 1; ++i) {
        while (!q.empty() && i - (int)q.front().se > k) {
            q.pop_front();
        }
        int val = (s[i] == '1' ? 0 : a[i]);
        f[i] = q.front().fi + val;
        while (q.size() && f[i] <= q.back().fi) {
            q.pop_back();
        }
        q.emplace_back(f[i], i);
    }

    while (q.size()) {
        q.pop_back();
    }

    g[n + 1] = 0;
    q.emplace_back(g[n + 1], n + 1);
    for (int i = n; i >= 0; --i) {
        while (q.size() && q.front().se - i > k) {
            q.pop_front();
        }
        int val = (s[i] == '1' ? 0 : a[i]);
        g[i] = q.front().fi + val;
        while (q.size() && g[i] <= q.back().fi) {
            q.pop_back();
        }
        q.emplace_back(g[i], i);
    }
    buildRMQ(rmqf, f);
    buildRMQ(rmqg, g);

    int Q;
    cin >> Q;
    while (Q--) {
        int p, v;
        cin >> p >> v;
        long long ntot = tot;
        if (s[p] == '1') {
            ntot += v - a[p];
        }
        long long cost = getRMQ(rmqf, max(0, p - k), p - 1);
        cost += getRMQ(rmqg, p + 1, min(n + 1, p + k));

        if (s[p] == '0') {
            cost += v;
        }

        for (int i = max(0, p - k); i < p; ++i) {
            cost = min(cost, f[i] + getRMQ(rmqg, p + 1, min(n + 1, i + k)));
        }
        for (int i = p + 1; i <= min(n + 1, p + k); ++i) {
            cost = min(cost, g[i] + getRMQ(rmqf, max(0, i - k), p - 1));
        }
        cout << cost + ntot << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    int T;
    cin >> T;

    for (int i = 1; i < N; ++i) {
        LG[i] = log2(i);
    }

    while (T--) {
        solve();
    }
}