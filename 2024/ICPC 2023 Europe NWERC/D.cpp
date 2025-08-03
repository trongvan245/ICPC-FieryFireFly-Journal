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
    vector<int> a(7, 0);

    for (int i = 0; i < 7; ++i) {
        for (int h = 0; h < 24; ++h) {
            char x; cin >> x;
            a[i]+= (x == '.') << h;
        }
    }

    int d, h; cin >> d >> h;

    ld ans= 0;
    for (int mask  = 1; mask < (1 << 24); ++ mask) {
        int cnt= __builtin_popcount(mask);
        if (cnt != h) continue;
        vector<int> val;

        for (int i = 0; i < 7; ++i) 
            val.pb(__builtin_popcount(mask & a[i]));
        
        sort(val.begin(), val.end(), greater<int>());

        ld res= 0;
        for (int i = 0; i < d; ++i) res+= val[i];
        ans= max(ans, res);
    }

    cout <<fixed<<setprecision(12)<<(ans / (1.0 * d * h));

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