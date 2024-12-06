#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

struct Hull {
    long long a[MAXN], b[MAXN];
    double x[MAXN];
    int head, tail;

    Hull(): head(1), tail(0) {}

    long long get(long long xQuery) {
        if (head > tail) return 0;
        while (head < tail && x[head + 1] <= xQuery) head++;
        x[head] = xQuery;
        return a[head] * xQuery + b[head];
    }

    void add(long long aNew, long long bNew) {
        double xNew = -1e18;
        while (head <= tail) {
            if (aNew == a[tail]) return;
            xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
            if (head == tail || xNew >= x[tail]) break;
            tail--;
        }
        a[++tail] = aNew;
        b[tail] = bNew;
        x[tail] = xNew;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<long long> f(n, 1e18), g(n, 1e18);

    f[s] = 0;
    priority_queue
}