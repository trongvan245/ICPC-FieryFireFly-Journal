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
    int n;
    vector<int> a(50);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        a[i] = (s[0] - '0') * 60 + (s[2] - '0') * 10 + (s[3] - '0');
    }

    int ans = 0;
    for (int time = 7 * 60; time <= 9 * 60; ++time) {
        int l = time, r = time + 10;
        int Count = 0;
        for (int i = 1; i <= n; ++i)
            if (l <= a[i] && a[i] <= r)
                ++Count;
        ans = max(ans, Count);
    }

    cout << max(0, 3 - ans);
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