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

struct fenwick {
    vector<int> fw;
    int n;
    fenwick(int x) {
        n = x;
        fw.resize(n + 5);
    }
    void upd(int i, int val) {
        for (; i <= n; i += i & (-i))
            fw[i] += val;
    }
    void upd(int l, int r, int val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    int get(int pos) {
        int ans = 0;
        for (; pos >= 1; pos -= pos & (-pos))
            ans += fw[pos];
        return ans;
    }
    int get(int l, int r) {
        int ans = 0;
        ans += get(r) - get(l - 1);
        return ans;
    }
    void clear() {
        for (int i = 1; i <= n; ++i)
            fw[i] = 0;
    }
};

void xuly() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(m + 1, 0);
    fenwick fw(n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (pos[x]) {
            fw.upd(pos[x], -1);
            ans += fw.get(pos[x], i);
        } else
            ans += fw.get(1, i) * 2;

        fw.upd(i, 1);
        pos[x] = i;

        // cout << i << " " << ans << '\n';
    }

    int cnt = fw.get(1, n);
    for (int i = 1; i <= m; ++i) {
        if (!pos[i])
            ans += cnt;
    }

    cout << ans;
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