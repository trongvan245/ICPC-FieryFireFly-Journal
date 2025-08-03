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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + m + 1), pay(n + m + 1);
    stack<pii> st;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // for (int i = 1; i < m; ++i) st.push({a[i], i});

    for (int i = 1; i <= n + m - 1; ++i) {
        if (i <= n) st.push({a[i], i});
        if (i >= m)
        k+= pay[i - m];
        // cout << i <<" "<<pay[i-m]<< " " << k <<'\n';
        while(k > 0 && st.size()) {
            auto [val, id]= st.top(); st.pop();
            if (i - id >= m) continue;
            if (k >= val) {
                k-= val;
                pay[id]+= val;
                // cout << id <<" "<<val<<'\n';
            }
            else {
                val-= k;
                pay[id]+= k;
                k= 0;
                st.push({val, id});
            }
        }
    }

    ll ans= 0;
    for (int i= 1; i <= n; ++i) ans+= pay[i];
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