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
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

int n, m, s;
int a[15], b[15];
int res[1000005];

void xuly() {
    cin >> m >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];

    res[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (int i = 1; i <= n; ++i) {
            int v = (1ll * u * a[i] + b[i]) % m;

            if (!res[v]) {
                res[v] = res[u] + 1;
                q.push(v);
            }
        }
    }

    cout << res[0] - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    xuly();
}

// Surely nothing could go wrong.