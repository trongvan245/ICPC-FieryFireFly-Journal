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

const int N = 505;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, m, Count;
ll ans;
char a[N][N];
int low[N * N], id[N * N], deleted[N * N], d[N][N];
vector<int> adj[N * N];
stack<int> st;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int vis[N * N], root[N * N], active[N * N], cnt[N * N];
int find(int v) {
    if (root[v] != v)
        return root[v] = find(root[v]);
    return root[v];
}
void dfs(int u) {
    vis[u] = true;
    root[u] = u;
    st.push(u);
    for (int v : adj[u])
        if (vis[v]) {
            v = find(active[v]);
            while (st.top() != v) {
                root[find(st.top())] = v;
                st.pop();
            }
        }

    for (int v : adj[u])
        if (!vis[v]) {
            active[u] = v;
            dfs(v);
        }

    if (st.top() == u)
        st.pop();
}

void xuly() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '#')
                continue;
            d[i][j] = ++Count;
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '#')
                continue;
            for (int k = 0; k <= 3; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x <= 0 || y <= 0 || x > n || y > m)
                    continue;
                if (a[x][y] == '#')
                    continue;
                adj[d[i][j]].pb(d[x][y]);
            }
        }

    for (int i = 1; i <= Count; ++i) {
        if (!vis[i]) {
            dfs(i);
            ans += 2;
        }
    }

    for (int i = 1; i <= Count; ++i)
        cnt[find(i)]++;

    for (int i = 1; i <= Count; ++i) {
        // cout << i << " " << cnt[i] << '\n';
        ++cnt[i];
        ans -= 1ll * cnt[i] * (cnt[i] - 1);
    }

    ans += 1ll * Count * (Count - 1);

    cout << ans;
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