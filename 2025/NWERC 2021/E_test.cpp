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

tuple<int, int, vector<pair<int, int>>> xuly(int a, int b) {
    if (a < b) {
        assert(false);
        if (a != b - 1) {
            cout << "impossible" << '\n';
            return {1, 1, {}}; 
        }

        int n = b, m = b;
        vector<pair<int, int>> edges;

        for (int i = 2; i < b; ++i) {
            edges.push_back({i, 1});
        }
        // cout << b << " " << b - 1 << '\n';
        // for (int i = 2; i < b; ++i) {
        //     cout << i << " " << 1 << '\n';
        // }
        return {n, m, edges};
    }
    
    if (b == 1) {
        b *= 3000, a *= 3000;
    }
    else {
        b = b * 1000, a = a * 1000;
    }

    a -= b - 1;

    vector<int> d(b + 1, 0);
    int maxx = -1;
    for (int i = 2; i <= b; ++i) {
        d[i] = min(a, maxx + 1);
        a -= d[i];
        maxx = max(d[i], maxx);
    }

    int n = b, m = b - 1;
    vector<pair<int, int>> edges;
    // cout << b << " " << b - 1 << '\n';
    int ss = 0;
    for (int i = 2; i <= b; ++i) {
        d[i] += 1;
        ss += d[i];
        edges.push_back({i, d[i]});
        // cout << i << " " << d[i] << '\n';
    }
    return {n, m, edges};
}

void checker(int a, int b, int n, int m, vector<pair<int, int>> edges) {
    // ifstream inp("test.out");
    // int n, m;
    // inp >> n >> m;

    queue<int> q;
    vector<vector<int>> adj(n + 1);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n + 1, 0);
    q.push(1);
    while(q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (v != 1 && dist[v] == 0) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += dist[i];
    }
    if (1ll * a * n != 1ll * b * s) {
        cout << "Wrong testcase : " <<'\n';
        cout << a << " " << b << '\n';
        cout << s << " " << n << '\n';
        cout << '\n';
        // return;
        assert(false);
    }
    // inp.close();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    int t = 1;
    // cin >> t;

    for (int a = 1000; a >= 1; --a)
    for (int b = a; b >= 1; --b) {
        auto [n, m, edges] = xuly(a, b);
        checker(a, b, n, m, edges);
        cout << a << " " << b << " " << "ok \n";
        cout.flush();
    }
}

// Surely nothing could go wrong.