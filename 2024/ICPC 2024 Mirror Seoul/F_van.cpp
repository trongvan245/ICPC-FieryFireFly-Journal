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
    int pos, u, v;
};
vector<three> ans;

int n;
int a[N], b[N];

int pre(int x) { return max(a[x - 1], b[x - 1]); }
void query(int pos, int x, int y) {
    assert(pos >= 1 && pos < n);
    if (a[pos] != x)
        swap(a[pos], b[pos]);
    if (a[pos + 1] != y)
        swap(a[pos + 1], b[pos + 1]);

    assert(a[pos] == x);
    assert(a[pos + 1] == y);
    swap(a[pos], a[pos + 1]);
    ans.pb({pos, x, y});
}
void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = b[i] = n - i + 1;

    for (int i = 1; i <= n; ++i) {
        while (!(a[i] == i && b[i] == i)) {
            vector<int> pos;
            for (int j = 1; j <= n; ++j) {
                if (a[j] == i)
                    pos.pb(j);
                if (b[j] == i)
                    pos.pb(j);
            }

            int x = pos[0], y = pos[1];
            if (pre(x) > pre(y))
                query(x - 1, pre(x), i);
            else
                query(y - 1, pre(y), i);
        }
    }
    cout << ans.size() << '\n';
    for (auto [pos, u, v] : ans)
        cout << pos << " " << u << " " << v << '\n';

    // for (int i = 1; i <= n; ++i)
    //     cout << a[i] << " ";
    // cout << '\n';
    // for (int i = 1; i <= n; ++i)
    //     cout << b[i] << " ";
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