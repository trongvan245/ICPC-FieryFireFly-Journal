#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

struct SegTree {
    vector<int> st;
    SegTree() {}
    SegTree(int n) {
        st.assign(4 * n + 5, 0);
    }

    void update(int i, int l, int r, int p, int val) {
        if (l == r) {
            st[i] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) {
            update(i * 2, l, mid, p, val);
        } else {
            update(i * 2 + 1, mid + 1, r, p, val);
        }
        st[i] = st[i * 2] + st[i * 2 + 1];
    }
    int get(int i, int l, int r, int k) {
        if (l == r) {
            return l;
        }
        int mid = (l + r) >> 1;
        if (k > st[i * 2]) {
            return get(i * 2 + 1, mid + 1, r, k - st[i * 2]);
        }
        return get(i * 2, l, mid, k);
    }
    long long getRange(int i, int l, int r, int u, int v) {
        if (u > r || v < l) {
            return 0;
        }
        if (u <= l && r <= v) {
            return st[i];
        }
        int mid = (l + r) >> 1;
        return getRange(i * 2, l, mid, u, v) + getRange(i * 2 + 1, mid + 1, r, u, v);
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    vector<int> p(n);
    int root = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        if (p[i] == -1) {
            root = i;
            continue;
        }
        adj[p[i]].push_back(i);
    }   
    
    vector<vector<pair<int, int>>> qr(n);
    for (int i = 0; i < q; ++i) {
        long long k;
        cin >> k;
        k--;
       qr[k / n].push_back({k % n + 1, i}); 
    }
    

    vector<int> sub(n), tin(n), tout(n), dep(n);
    vector<vector<int>> anc(n, vector<int>(20, root));
    vector<int> ver(2 * n, 0);
    int timer = 0;
    function<void(int)> dfs = [&](int u) {
        sub[u] = 1;
        tin[u] = ++timer;
        ver[tin[u]] = u;
        for (int i = 1; i < 20; ++i) {
            anc[u][i] = anc[anc[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            anc[v][0] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
            sub[u] += sub[v];
        }
        tout[u] = timer;
    };
    

    dfs(root);

    function<int(int, int)> findAnc = [&](int u, int ancestor) -> int {
        for (int i = 19; i >= 0; --i) {
            if (dep[u] - (1 << i) > dep[ancestor]) {
                u = anc[u][i];
            }
        }
        return u;
    };

    vector<long long> currentSum(q);
    SegTree st(n);
    vector<vector<int>> qr1(n);
    vector<int> need(q);
    

    function<void(int)> dfs1 = [&](int u) -> void {
        st.update(1, 0, n - 1, u, sub[u]);
        for (auto [nth, qrIndex]: qr[u]) {
            int lca = st.get(1, 0, n - 1, nth);
            int x = u;
            currentSum[qrIndex] = 1LL * x * n * n + 1LL * lca * n;
            need[qrIndex] = nth - st.getRange(1, 0, n - 1, 0, lca - 1);

            if (lca == x) {
                qr1[lca].emplace_back(qrIndex + 1);
                continue;
            }
            int nearestChildBelowY = findAnc(x, lca);
            qr1[lca].push_back(qrIndex + 1);
            qr1[nearestChildBelowY].push_back(-qrIndex - 1);
        }
        st.update(1, 0, n - 1, u, -sub[u]);
        for (int v : adj[u]) {
            st.update(1, 0, n - 1, u, sub[u] - sub[v]);
            dfs1(v);    
            st.update(1, 0, n - 1, u, -(sub[u] - sub[v]));
        }
    };
    
    dfs1(root);

    vector<int> l(q, 0), r(q, n - 1), mid(q);
    
    vector<int> delta(q, 0);


    st = SegTree(n);
    function<void(int, int, bool)> dfs2 = [&](int v, int p, bool keep) {
        int mx = -1, bigChild = -1;
        for(auto u : adj[v])
        if(u != p && sub[u] > mx)
            mx = sub[u], bigChild = u;
        for(auto u : adj[v])
            if(u != p && u != bigChild)
                dfs2(u, v, 0); 
        if(bigChild != -1)
            dfs2(bigChild, v, 1);  
        for(auto u : adj[v])
            if(u != p && u != bigChild)
                for(int p = tin[u]; p <= tout[u]; p++) {
                    st.update(1, 0, n, ver[p], 1);
                }
        st.update(1, 0, n, v, 1);
        for (int qrindex: qr1[v]) {
            int mul = (qrindex > 0 ? 1 : -1);   
            int index = abs(qrindex) - 1;
            delta[index] += mul * st.getRange(1, 0, n, 0, mid[index]);
            // cout << v << ' ' << need[index] << ' ' << mid[index]<< ' ' << delta[index] << ' ' << st.getRange(1, 0, n, 0, mid[index]) << endl;
        }
        if(keep == 0)
            for(int p = tin[v]; p <= tout[v]; p++)
            st.update(1, 0, n, ver[p], -1);
    };
    

    vector<int> ans(q);
    while (true) {
        for (int i = 0; i < q; ++i) {
            delta[i] = 0;
        }
        st = SegTree(n);
        bool ok = false;
        delta = vector<int>(q, 0);
        for (int i = 0; i < q; ++i) {
            if (l[i] <= r[i]) {
                mid[i] = (l[i] + r[i]) >> 1;
                ok = true;
            }
        }
        if (!ok) {
            break;
        }
        dfs2(root, -1, 1);
        for (int i = 0; i < q; ++i) {
            if (delta[i] >= need[i]) {
                r[i] = mid[i] - 1;
                ans[i] = mid[i];
            } else {
                l[i] = mid[i] + 1;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << currentSum[i] + ans[i] << '\n';
    }
}