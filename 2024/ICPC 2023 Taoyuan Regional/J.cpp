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

struct three {
    int dp, num, pre;
};
void add(three &a, int dp, int num, int u) {
    if (a.dp < dp) {
        a.dp = dp;
        a.num = num;
        a.pre = u;
    } else if (a.dp == dp) {
        a.dp = dp;
        a.num = max(a.num + num, 2);
        a.pre = u;
    }
}
int n, m;
void xuly() {

    string s;
    getline(cin, s);
    getline(cin, s);
    s = s + ',';

    int x = 0;
    vector<int> A;
    // cout << s << '\n';
    for (char v : s) {
        if (v == ',') {
            A.pb(x);
            x = 0;
            continue;
        }
        x = x * 10 + (v - '0');
    }
    // for (int v : A)
    //     cout << v << " ";
    // cout << '\n';
    A.pb(0);
    vector<vector<pii>> adj(n + 20, vector<pii>(0));
    vector<int> deg(n + 20, 0);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        ++deg[v];
    }
    vector<three> dp(n + 1, {0, 0, 0});

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        adj[i].pb({n, 0});
        ++deg[n];

        if (deg[i] == 0) {
            q.push(deg[i]);
            dp[i] = {A[i], 1, -1};
        }
    }

    while (q.size()) {
        int u = q.front();
        q.pop();
        // cout << u << " " << dp[u].dp << '\n';
        for (auto [v, w] : adj[u]) {
            assert(u <= n && v <= n);
            add(dp[v], dp[u].dp + w + A[v], dp[u].num, u);
            --deg[v];
            if (deg[v] == 0)
                q.push(v);
        }
    }

    cout << dp[n].dp;

    if (dp[n].num == 2) {
        cout << ",M\n";
        return;
    }

    int curr = dp[n].pre;
    vector<int> tv;
    while (curr != -1) {
        tv.pb(curr);
        curr = dp[curr].pre;
    }
    reverse(tv.begin(), tv.end());

    for (int v : tv)
        cout << ',' << v;
    cout << '\n';
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
    n = -1;
    while (true) {
        cin >> n >> m;
        if (n == -1)
            break;
        xuly();
        n = -1;
    }
}

// Surely nothing could go wrong.