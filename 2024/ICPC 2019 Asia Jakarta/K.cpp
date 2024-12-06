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
using type = int; // Kiểu dữ liệu các phần tử của ma trận

vector<vector<int>> A({{1, 0}, {1, 1}}), B({{1, 1}, {0, 1}}),
    I({{1, 0}, {0, 1}});

vector<vector<int>> mul(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> C(2, vector<int>(2, 0));

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                (C[i][j] += 1ll * A[i][k] * B[k][j] % mod) %= mod;

    return C;
}
struct Segment_Tree {
    vector<vector<vector<int>>> st, flip;
    vector<int> lazy;
    int NN;
    Segment_Tree(int n) {
        st.assign(4 * n + 5, I);
        flip.assign(4 * n + 5, I);
        lazy.assign(4 * n + 5, 0);
        NN = n;
    }

    void down(int id) {
        if (lazy[id]) {
            swap(st[id * 2], flip[id * 2]);
            swap(st[id * 2 + 1], flip[id * 2 + 1]);
            lazy[id * 2] ^= 1;
            lazy[id * 2 + 1] ^= 1;
            lazy[id] = 0;
        }
    }
    void upd(int l, int r) { upd(1, 1, NN, l, r); }
    void upd(int id, int l, int r, int u, int v) {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v) {
            lazy[id] ^= 1;
            swap(st[id], flip[id]);
            return;
        }
        down(id);
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, u, v);
        upd(id * 2 + 1, mid + 1, r, u, v);
        st[id] = mul(st[id * 2], st[id * 2 + 1]);
        flip[id] = mul(flip[id * 2], flip[id * 2 + 1]);

        // st[id] = st[id * 2] * st[id * 2 + 1];
        // flip[id] = flip[id * 2] * flip[id * 2 + 1];
    }

    void build(string &s) { build(1, 1, NN, s); }
    void build(int id, int l, int r, string &s) {
        if (l == r) {
            st[id] = A, flip[id] = B;
            if (s[l] == 'B')
                swap(st[id], flip[id]);
            return;
        }
        int mid = (l + r) / 2;

        build(id * 2, l, mid, s);
        build(id * 2 + 1, mid + 1, r, s);

        st[id] = mul(st[id * 2], st[id * 2 + 1]);
        flip[id] = mul(flip[id * 2], flip[id * 2 + 1]);
        // st[id] = st[id * 2] * st[id * 2 + 1];
        // flip[id] = flip[id * 2] * flip[id * 2 + 1];
        // cout << "build" << " " << id << " " << l << " " << r << '\n';
        // cout << st[id] << '\n';
    }

    vector<vector<int>> get(int l, int r) { return get(1, 1, NN, l, r); }

    vector<vector<int>> get(int id, int l, int r, int u, int v) {
        // cout << id << " " << l << " " << r << " " << u << " " << v << '\n';
        // cout << st[id] << "\n\n";
        if (l > v || r < u)
            return I;
        if (l >= u && r <= v)
            return st[id];
        down(id);
        int mid = (l + r) / 2;
        return mul(get(id * 2, l, mid, u, v),
                   get(id * 2 + 1, mid + 1, r, u, v));
        // return get(id * 2, l, mid, u, v) * get(id * 2 + 1, mid + 1, r, u, v);
    }
};

void xuly() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    s = " " + s;

    Segment_Tree st(n + 5);
    st.build(s);
    ld upd_time = 0;
    clock_t begin = clock();
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            clock_t begin = clock();
            st.upd(l, r);
            // upd_time += (double)(clock() - begin) / CLOCKS_PER_SEC;
            // cerr << "TIME : " << (double)(clock() - begin) / CLOCKS_PER_SEC
            //      << "s.";
        } else {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            vector<vector<int>> res = st.get(l, r);
            int resa = (1ll * a * res[0][0] + 1ll * b * res[1][0]) % mod;
            int resb = (1ll * a * res[0][1] + 1ll * b * res[1][1]) % mod;
            cout << resa << " " << resb << '\n';
        }
    }
    // cerr << "TIME : " << (double)(clock() - begin) / CLOCKS_PER_SEC << "s.";
    // cerr << "TIME : " << upd_time << "s.";
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