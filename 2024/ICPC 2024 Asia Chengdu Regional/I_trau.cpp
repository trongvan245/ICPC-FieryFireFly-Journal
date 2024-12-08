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

int n, q;
int a[N];

int check() {
    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        int flag = true;
        for (int i = 1; i <= n; i += k) {
            for (int c = i + 1; c <= i + k - 1 && c <= n; ++c)
                if (a[c - 1] > a[c])
                    flag = false;
        }

        ans += flag;
    }
    return ans;
}

void xuly() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cout << check() << '\n';
    while (q--) {
        int u, v;
        cin >> u >> v;
        a[u] = v;
        cout << check() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".ans", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.