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
const long long mod = 998244353;

using namespace std;

void xuly() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = ((int)s1.size() + 2) / 3;

    auto check = [&](string s) {
        vector<pii> pos(n);
        stack<int> st;
        int Count = 0;
        for (char v : s) {
            if (v == '(')
                continue;
            if (v == '1') {
                st.push(1);
                ++Count;
            } else {
                int v = st.top();
                st.pop();
                int u = st.top();
                st.pop();

                pos[Count - v] = {u, v};
                st.push(u + v);
            }
        }

        return pos;
    };

    vector<pii> t1, t2;
    t1 = check(s1), t2 = check(s2);

    ll ans = 1;
    for (int i = 1; i < n; ++i) {
        int l = min(t1[i].fi, t2[i].fi);
        int r = min(t1[i].se, t2[i].se);
        int res = (1ll * l * r) % mod;
        ans = ans * res % mod;
    }
    cout << ans << '\n';
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