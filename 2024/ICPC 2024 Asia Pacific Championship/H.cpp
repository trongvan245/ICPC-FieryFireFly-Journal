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
    int ans= 0;
    vector<string> s(n);
    vector<pii> cnt(n);

    bool is_1= false, is_0= false;
    int minn= 1e9;
    bool t1= false, t0= false;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        auto &[c1, c0]= cnt[i];
        for (char v : s[i]) if (v == '1') ++c1; else ++c0;

        if (c1 >= c0) is_1= true;
        if (c0 >= c1) is_0= true;
        ans+= min(c1, c0);
        minn= min(minn, abs(c0 - c1));

        if (c1) t1= true;
        if (c0) t0= true;
    }

    if (!t1 || !t0) {
        cout << 0 << '\n';
        return;
    }


    if (!is_1 || !is_0) {
        cout << ans + minn << '\n';
    }
    else cout << ans << '\n';
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