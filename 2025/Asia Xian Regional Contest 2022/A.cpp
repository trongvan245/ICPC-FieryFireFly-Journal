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
const long long mod = 1e9 + 7; // 998244353;
const int S = 350;

using namespace std;

struct query {
    int t, a, b;
};
vector<query> queries;
vector<int> c[N];
pair<int, int> nodes[5 * N];
int pre[5 * N], st[5 * N];
map<pair<int, int>, int> mmap;
int idx = 0;
int p[S + 5][N];


void xuly() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= q; ++i) {
        int t, a, b;
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            --b;
            c[a].push_back(b);
            c[a + 1].push_back(b);
            mmap[{a, b}] = ++idx;
            nodes[idx] = {a, b};
            mmap[{a + 1, b}] = ++idx;
            nodes[idx] = {a + 1, b};
        }
        else {
            cin >> a;
        }
        queries.push_back({t, a, b});
    }
    for (int j = 0; j <= m; j += S) {
        for (int i = 1; i <= n; ++i) {
            c[i].push_back(j);
            mmap[{i, j}] = ++idx;
            nodes[idx] = {i, j};
            p[j / S][i] = i;
            st[idx] = idx;
        }
    }

    for (int i = 1; i <= n; ++i) {
        sort(c[i].begin(), c[i].end());
        for (int j = 1; j < c[i].size(); ++j) {
            int u = mmap[{i, c[i][j - 1]}];
            int v = mmap[{i, c[i][j]}];
            pre[v] = u;
        }
    }

    function<int(int)> get_pre = [&](int u) -> int {
        if (nodes[u].second % S == 0) return u;
        else return get_pre(pre[u]);
    };

    for (auto [t, a, b] : queries) {
        if (t == 1) {
            int chunk_idx = b / S;
            int u = get_pre(mmap[{a, b}]);
            int v = get_pre(mmap[{a + 1, b}]);
            u = st[u];
            v = st[v];
            int x = nodes[u].first, y = nodes[v].first;
            // cout << x << " " << y << '\n';
            // cout << u << " " << v << '\n';
            // cout << nodes[u].second << " " << nodes[v].second << '\n';
            // cout << p[chunk_idx][x] << " " << p[chunk_idx][y] << '\n';
            if (b % S == 0) {
                swap(st[u], st[v]);
            }
            else {
                swap(pre[mmap[{a, b}]], pre[mmap[{a + 1, b}]]);
            }
            swap(p[chunk_idx][x], p[chunk_idx][y]);
            // cout << p[chunk_idx][1] << " " <<p[chunk_idx][2] << '\n';
            // cout << '\n';
        }
        else {
            int pos = a;
            for (int chunk_idx = 0; chunk_idx <= m / S; ++ chunk_idx) {
                pos = p[chunk_idx][pos];
            }

            cout << pos << '\n';
        }
    }
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