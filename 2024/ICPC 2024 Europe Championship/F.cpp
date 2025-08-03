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
    int n, m;
    cin >> n >> m;

    vector<set<int>> activities(n + 1);
    vector<vector<int>> list_user(m + 1);
    vector<int> p(n + 1);

    map<pii, bool> is_cmp;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int u;
            cin >> u;
            activities[i].insert(u);

            list_user[u].pb(i);
        }
    }

    for (int i = 1; i <= m; ++i) {
        sort(list_user[i].begin(), list_user[i].end(),
             [&](int u, int v) { return activities[u].size() < activities[v].size(); });
    }

    auto not_in = [&](int u, int v) {
        if (activities[u].size() > activities[v].size())
            swap(u, v);

        for (auto str : activities[u]) {
            if (activities[v].find(str) == activities[v].end())
                return true;
        }

        return false;
    };

    for (int act = 1; act <= m; ++act) {
        for (int i = 1; i < list_user[act].size(); ++i) {
            int pre = list_user[act][i - 1], curr = list_user[act][i];

            if (!is_cmp[{pre, curr}]) {
                if (not_in(pre, curr)) {
                    cout << "YES\n";
                    cout << pre << " " << curr << '\n';
                    return;
                }
                is_cmp[{pre, curr}] = true;
            }
        }
    }

    cout << "NO\n";
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