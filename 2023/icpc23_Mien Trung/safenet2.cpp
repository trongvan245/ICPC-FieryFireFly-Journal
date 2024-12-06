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

int n, m;
int root[N], vis[N], active[N], ans[N];
vector<int> a[N];
stack<int> st;

int find(int v) {
    if (root[v] != v)
        return root[v] = find(root[v]);
    return root[v];
}

void dfs(int u) {
    vis[u] = true;
    root[u] = u;

    st.push(u);

    for (int v : a[u])
        if (vis[v]) {
            v = find(active[v]);
            while (st.top() != v) {
                root[find(st.top())] = v;
                st.pop();
            }
        }

    for (int v : a[u])
        if (!vis[v]) {
            active[u] = v;
            dfs(v);
        }
    if (st.top() == u)
        st.pop();
}

void xuly() {
    cin >> n >> m;
    if (m == 0) {
        cout << 1;
        return;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }

    int anss = 0;
    for (int i = 1; i <= n; ++i)
        ans[find(i)]++;
    for (int i = 1; i <= n; ++i)
        anss = max(anss, ans[i]);

    cout << anss + 1;
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