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

int n, q;
int a[N];
vector<int> st[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].pb(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    vector<int>& A = st[id * 2];
    vector<int>& B = st[id * 2 + 1];
    int p1 = 0, p2 = 0;

    while (p1 < A.size() && p2 < B.size()) {
        if (A[p1] <= B[p2])
            st[id].pb(A[p1++]);
        else
            st[id].pb(B[p2++]);
    }

    while (p1 < A.size())
        st[id].pb(A[p1++]);
    while (p2 < B.size())
        st[id].pb(B[p2++]);

    // cout << id << " " << l << " " << r << " " << st[id].size() << '\n';
}

int get(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u)
        return 0;
    if (l >= u && r <= v) {
        // return 1;
        // cout << l << " " << r << '\n';
        int l = 0, r = (int)st[id].size() - 1, res = -1;

        // cout << l << " " << r << "asdf\n";
        while (l <= r) {
            int mid = (l + r) / 2;
            if (st[id][mid] <= val) {
                l = mid + 1;
                res = mid;
            } else
                r = mid - 1;
        }

        return res + 1;
    }

    int mid = (l + r) / 2;

    return get(id * 2, l, mid, u, v, val) +
           get(id * 2 + 1, mid + 1, r, u, v, val);
}

void xuly() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;

        int num = (r - l + 2) / 2;
        int L = 1, R = 1e5, res = 0;

        // cout << get(1, 1, n, l, r, 10) << '\n';
        // continue;
        // cout << l << " " << r << " " << num << '\n';
        while (L <= R) {
            int mid = (L + R) / 2;
            int t1 = get(1, 1, n, l, r, mid);

            // cout << mid << " " << t1 << '\n';
            if (t1 < num) {
                L = mid + 1;
                res = mid;
            } else
                R = mid - 1;
        }

        cout << res + 1 << '\n';
    }
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