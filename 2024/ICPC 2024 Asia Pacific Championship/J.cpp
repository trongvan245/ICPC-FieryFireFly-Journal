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
const long long mod = 1e9 + 7; // 998244353;

using namespace std;


vector<pii> adj[N];
map<pii, bool> is_check;
int dist1[N];
int dist[N][2];
int pre[N];

void xuly() {
    int n, m; cin >> n >> m;
    
    for (int i=1;i<=m;++i) {
        int u, v, w; cin >>u>>v>>w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for (int i=1;i<=n;++i) dist[i][0]= dist[i][1]= dist1[i]= 1e9;



    auto first_dijkstra= [&]() {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> pre(n+1);
        dist1[1]= 0;
        pq.push({0, 1});
        while(pq.size()) {
            auto [w, u]= pq.top(); pq.pop();
            if (w > dist1[u]) continue;
            for (auto [v, W] : adj[u]) {
                if (w + W < dist1[v]) {
                    dist1[v]= w + W;
                    pre[v]= u;
                    pq.push({w + W, v});
                }
            }
        }   

        int curr= n;
        while(curr != 1 && curr != 0) {
            is_check[{curr, pre[curr]}] = is_check[{pre[curr], curr}]= true;
            curr= pre[curr];

        }

        return dist1[n];
    };

    int first_path= first_dijkstra();


    auto second_dijkstra= [&]() {
        dist[1][0]= 0;
        
        struct three {
            int w, u, t;
            bool operator>(const three &other) const {
                return this->w > other.w;
            }
        };
        priority_queue<three, vector<three>, greater<three>> pq;

        pq.push({0, 1, 0});
        dist[1][0]= 0;
        while(pq.size()) {
            auto [w, u, t]= pq.top(); pq.pop();
            if (w > dist[u][t]) continue;
    
            for (auto [v, W] : adj[u]) {
                bool check= is_check[{u, v}];

                bool nxt= (!check) | t;

                if (w + W < dist[v][nxt]) {
                    pq.push({w + W, v, nxt});
                    dist[v][nxt]= w + W;
                }
            }
        }

        return dist[n][1];
    };

    int second_path= second_dijkstra();

    int ans= first_path + second_path;
    if (ans >= 1e9) ans= -1;

    cout << ans<< '\n';
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