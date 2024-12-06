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

char a[205][205];
int r, c;
vector<string> ans;
bool vis[205][205];
char reflec[500][500];
int dx[500], dy[500];

bool start(char dir, int x, int y) {
    // cout << dir << " " << x << " " << y << '\n';
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            vis[i][j] = false;

    while (true) {
        // cout << x << " " << y << " " << dir << '\n';
        vis[x][y] = true;
        x += dx[dir], y += dy[dir];
        vis[x][y] = true;
        if (x == 0 || y == 0 || x == r + 1 || y == c + 1)
            break;
        dir = reflec[a[x][y]][dir];
    }

    // for (int i = 1; i <= r; ++i, cout << '\n')
    //     for (int j = 1; j <= c; ++j)
    //         cout << vis[i][j] << " ";
    // cout << "\n\n";
    bool flag = true;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (a[i][j] != '.' && !vis[i][j])
                flag = false;

    return flag;
}

void init() {
    dx['U'] = -1;
    dx['D'] = 1;
    dy['L'] = -1;
    dy['R'] = 1;

    reflec['.']['U'] = 'U';
    reflec['.']['D'] = 'D';
    reflec['.']['L'] = 'L';
    reflec['.']['R'] = 'R';

    reflec['/']['U'] = 'R';
    reflec['/']['D'] = 'L';
    reflec['/']['L'] = 'D';
    reflec['/']['R'] = 'U';

    reflec['\\']['U'] = 'L';
    reflec['\\']['D'] = 'R';
    reflec['\\']['L'] = 'U';
    reflec['\\']['R'] = 'D';
}
void xuly() {
    init();
    cin >> r >> c;

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> a[i][j];

    vector<pair<char, string>> ans;
    for (int i = 1; i <= r; ++i) {
        if (start('R', i, 0))
            ans.pb({'W', to_string(i)});
        if (start('L', i, c + 1))
            ans.pb({'E', to_string(i)});
    }

    for (int j = 1; j <= c; ++j) {
        if (start('D', 0, j))
            ans.pb({'N', to_string(j)});
        if (start('U', r + 1, j))
            ans.pb({'S', to_string(j)});
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << u << v << " ";
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