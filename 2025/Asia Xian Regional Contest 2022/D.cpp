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

int a[10][N], r[10][N];
int vis[N];

void xuly() {
    int n, m;
    cin >> n >> m;
    for (int j = 1; j <= m; ++j)
    for (int i = 1; i <= n; ++i) {
        cin >> a[j][i];
        r[j][a[j][i]] = i;
    }   

    queue<int> q;
    for (int j = 1; j <= m; ++j) {
        q.push(a[j][1]);
        vis[a[j][1]] = 1;
    }

    while(q.size()) {
        int u = q.front(); q.pop();
        // cout << u << '\n';

        for (int j = 1; j <= m; ++j) {
            int i = r[j][u] - 1;
            // cout << j << " " << i << " " << a[j][i] << '\n';
            while(vis[a[j][i]] == 0 && i > 0) {
                vis[a[j][i]] = vis[u] + 1;
                q.push(a[j][i]);
                --i;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << vis[i] << " ";
    }
    cout << '\n';

    int qq; cin >> qq;
    while(qq--) {
        int u, v; cin >> u >> v;
        int ans = (vis[u] ? vis[v] - vis[u]: -1);
        ans = max(ans, -1);
        for (int j = 1; j <= m; ++j) {
            if (r[j][u] < r[j][v]) {
                ans = 1;
            }
        }
        
        cout << ans << '\n';
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