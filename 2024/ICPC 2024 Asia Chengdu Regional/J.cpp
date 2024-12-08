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

int finish[N];
ll res[N];
void xuly() {

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i)
        res[i] = 0, finish[i] = 0;
    int stage = -1;
    int score = m;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> stage;
            score = m;
        } else if (t == 2) {
            int id, x;
            cin >> id >> x;
            if (x != stage)
                continue;
            if (finish[id] == stage)
                continue;
            finish[id] = stage;
            res[id] += score--;
        } else {
            int id, x;
            cin >> id >> x;
            if (x != stage)
                continue;
            if (finish[id] == stage)
                continue;
            finish[id] = stage;
        }
    }

    vector<pair<ll, ll>> A;
    for (int i = 1; i <= m; ++i)
        A.pb({-res[i], i});

    sort(A.begin(), A.end());
    for (auto [u, v] : A)
        cout << v << " " << -u << '\n';
    // cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.