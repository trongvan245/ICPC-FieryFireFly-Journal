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

int n, e;
string s[105];

void xuly() {
    cin >> n >> e;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    auto check = [&](char c) -> int {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int Count = 0;
            for (int v : s[i])
                if (v != c)
                    break;
                else
                    ++Count;
            if (Count == s[i].size())
                return 1e9;

            res += Count;
        }
        return res;
    };

    pii ans = {1e9, '?'};
    for (char c = 'a'; c <= 'a' + e - 1; ++c) {
        int res = check(c);
        ans = min(ans, {res, c});
    }
    // cout << ans.fi << " " << ans.se << '\n';

    if (ans.fi == 1e9)
        cout << "NO";
    else
        for (int i = 1; i <= ans.fi + 1; ++i)
            cout << char(ans.se);
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