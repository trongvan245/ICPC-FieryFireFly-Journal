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
    vector<vector<int>> adj(n + 1);

    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        adj[x].push_back(i);
    }

    vector<int> res;
    function<int(int)> dfs = [&](int u) -> int {
        if (adj[u].size() == 0) {
            return 1;
        }
        vector<int> A;
        for (int v : adj[u]) {
            A.push_back(dfs(v));
        }

        sort(A.begin(), A.end(), greater<int>());
        for (int i = 1; i < A.size(); ++i) {
            res.push_back(A[i]);
        }

        return A[0] + 1;
    };

    res.push_back(dfs(1));
    sort(res.begin(), res.end());

    
    int ans = res.size();
    int maxx = 0;
    for (int i = 0; i < res.size(); ++i) {
        maxx = max(res[i], maxx);
        ans = min(ans, maxx + (int)res.size() - (i + 1));
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
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.