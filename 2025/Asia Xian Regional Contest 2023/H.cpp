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

void xuly() {
    int n, k; cin >> n >> k;
    vector<int> a(1 << n), pos(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        cin >> a[i];
        pos[a[i] - 1] = i;
    }

    vector<int> st((4 << n) + 5, 0);
    vector<int> ans(1 << n, 0);
    int cnt = 0;
    function<void(int, int, int, int, int)> update = [&](int id, int l, int r, int pos, int w) {
        if (l > pos || r < pos) {
            return;
        }
        
        if (l == r) {
            ++st[id];
            cnt = 0;
            return;
        }

        int mid = (l + r) / 2;
        update(id * 2, l, mid, pos, w);
        update(id * 2 + 1, mid + 1, r, pos, w);

        st[id] = st[id * 2] + st[id * 2 + 1];
        
        if ((r - l + 1) - st[id] <= k && (r - l) <= w) {
            ++cnt;
        }
        // cout << id << " " << l << " " << r << " " << st[id] << " " << cnt << '\n';
    };


    int max_win = 0;
    for (int i = 0; i < (1 << n); ++i) {
        update(1, 0, (1 << n) - 1, pos[i], i);
        ans[pos[i]] = cnt;
    }

    for (int i = 0; i < (1 << n); ++i) {
        cout << ans[i] << " ";
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