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

bool vis[505][505][2];

void xuly() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;

    struct three {
        int x, y, type;
    };

    queue<three> q;
    vis[1][1][0]= true;
    vis[1][1][1]= true;
    q.push({1, 1, 0});
    q.push({1, 1, 1});

    int dx[4]= {1, 1, -1, -1};
    int dy[4]= {-1, 1, -1, 1};



    while(q.size()) {
        auto [u, v, type]= q.front(); q.pop();
        int wx, wy;
        if (!type) wx= a, wy= b;
        else wx= c, wy= d;

        for (int j=0;j<=1;++j) {
            swap(wx, wy);
            for (int i= 0; i < 4; ++i) {
                int x = u + dx[i] * wx, y = v + dy[i] * wy;
                if (x <= 0 || x > n || y <= 0 || y > n) continue;
                if (vis[x][y][!type]) continue;
    
                vis[x][y][!type]= true;
                q.push({x, y, !type});
            }
        }
    }

    int ans= 0;
    for (int i=1;i<=n;++i)
    for (int j=1;j<=n;++j) if (vis[i][j][1] || vis[i][j][0]) ++ans;

    cout << ans ;
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