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
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

char a[N];

const int brk = 21;

struct Node {
    int op1[brk][brk];
    int op2[brk][brk];
    int cx[brk][brk];
    int cy[brk][brk];
    int sz;
};

Node base_0, base_1;

void init() {
    base_0.op1[1][0] = 1;
    base_0.op2[1][0] = 1;
    base_0.cx[1][0] = base_0.cy[1][0] = 1;

    base_1.op1[0][1] = base_1.op2[0][1] = 1;
    base_1.cx[0][1] = base_1.cy[0][1] = 1;

    base_0.sz = base_1.sz = 1;
}

void merge(Node l, Node r) {
    for (int    )
}


Node st[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        if (a[l] == '(') {
            st[id] = base_0;
        }
        else st[id] = base_1;
    }
}


void xuly() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int op, l, r, k;
        cin >> op >> l >> r >> k;
        query[r].push_back({op, l, k, i});
    }
    
    for (int i = 1; i <= n; ++i) {
        update(1)
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