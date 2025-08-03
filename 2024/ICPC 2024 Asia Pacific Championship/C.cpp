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
    int n; cin >> n;
    vector<int> a(n);

    int minn= 1e9;
    for (int i= 0; i < n; ++i) {
        cin >> a[i];
        minn= min(a[i], minn);
    }


    
    auto check = [&](ll init) {
        vector<int> b(n);
        for (int i=0; i < n; ++i) {
            b[i]= __builtin_popcountll(init);
            ++init;
        }
        return (a == b);
    };

    if (minn == 0) {
        if (check(0)) cout << 0 << '\n';
        else cout << - 1 << '\n';
        return;
    }

    for (int i= 0 ; i < n; ++i) {
        if (a[i] != minn) continue;
        int saved= minn - 1;
        for (int j = 0 ; j < n; ++j) a[j]-= minn - 1;
        

        for (int j = 0 ; j <= 61; ++j) {
            ll init = (1ll << j) - i;
            if (check(init)) {
                ll maxx= init + (n - 1);
                for (int j = 0 ; j <= 61; ++j) {
                    if (saved == 0) break;
                    ll nxt= 1ll << j;
                    if (nxt <= maxx) continue;
                    init+= nxt;
                    --saved;
                }

                cout << init <<'\n';
                return;
            }
        }
        break;
    }

    cout << -1 << '\n';
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