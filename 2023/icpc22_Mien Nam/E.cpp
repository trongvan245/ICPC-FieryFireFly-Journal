// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan ""
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>
#define pdi pair<ld, ll>

typedef long double ld;
typedef long long ll;

const int N = 5e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n;
int a[N], b[N], p[N];
ld r[N];

vector<pdi> M;

ld st[4 * N];
int lazy_a[4*N], lazy_b[4*N], lazy_ab[4*N];


void down(int id) {
    for(int i=0;i<=1;++i) {
        lazy_a[id*2 + i]+= lazy_a[id];
        lazy_b[id*2 + i]+= lazy_b[id];
        lazy_ab[id*2 + i]+= lazy_ab[id];

    }
    lazy_a[id*2]+= lazy_a[id];
    lazy_a[id*2+1]+= lazy_a[id];
    
    lazy_a[id*2]+= lazy_a[id];
    lazy_a[id*2+1]+= lazy_a[id];
    lazy_a[id*2]+= lazy_a[id];
    lazy_a[id*2+1]+= lazy_a[id];
}
void upd(int id, int l, int r, int pos, ld res) {
    if (l > pos || r < pos)
        return;
    if (l == r) {
        st[id] = res;
        return;
    }
    down(id);
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, pos, res);
    upd(id * 2 + 1, mid + 1, r, pos, res);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void upd(int id, int l, int r, int v, int a, int b) {
    if (l > v) return;
    if (r <= v) {
        lazy_a[id]+= a*a;
        lazy_b[id]+= b*b;
        lazy_ab[id]+= 2*a*b;
    }
}

void xuly() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        r[i] = a[i] / (b[i] * 1.0);
        M.pb({r[i], i});
    }

    sort(M.begin(), M.end());

    for (int i = 0; i < M.size(); ++i) {
        p[M[i].se] = i + 1;
    }
    for (int i = 1; i <= 4 * n; ++i)
        st[i] = 1e9;
    for (int i = 1; i <= n; ++i) {
        ld res = get(1, 1, n, p[i] + 1, n);
        upd(1, 1, n, p[i], res);
        upd(1, 1, n, p[i] - 1, a[i], b[i]);
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