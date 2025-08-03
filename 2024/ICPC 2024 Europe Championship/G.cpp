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

int passenger = -1;
struct Path {
    int st, ed;
    vector<int> mid;
    Path(int st, int ed) : st(st), ed(ed) {};

    void add(int v) { mid.pb(v); }
    ádfasdf

        int
        Count() {
        return 2 + (int)mid.size() * 3 + 2;
    }

    void print() {

        auto drive =
            [&](int v) {
            query.pb({"DRIVE", v)
            cout << "DRIVE " << v << '\n'; };
        auto pickup = [&]() {
            cout << "PICKUP" << '\n'; };
        auto drop = [&]() {
            cout << "DROPOFF" << '\n'; };

        drive(st), pickup();

        for (int v : mid) {
            drive(v);
            drop();
            pickup();
        }

        if (ed != -1) {
            drive(ed), drop();
        }
            }
    };

    void xuly() {
        int n;
        cin >> n;
        vector<char> sub(n + 1), prof(n + 1);

        for (int i = 1; i <= n; ++i)
            cin >> sub[i];
        for (int i = 1; i <= n; ++i)
            cin >> prof[i];

        vector<Path> ans;
        vector<bool> vis(n + 1, false);

        for (int i = 1; i <= n; ++i) {
            if (sub[i] == prof[i]) {
                vis[i] = true;
                continue;
            }
        }

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (i == j || vis[i] || vis[j])
                    continue;

                if (sub[i] == '-' && prof[j] == '-' && prof[i] == sub[j]) {
                    Path N(i, j);
                    ans.pb(N);
                    vis[i] = vis[j] = true;
                }
            }

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (i == j || vis[i] || vis[j])
                    continue;

                if (sub[i] == '-' && prof[j] == '-' && prof[i] != sub[j]) {
                    vis[i] = vis[j] = true;
                    for (int k = 1; k <= n; ++k) {
                        if (!vis[k] && sub[k] == prof[i] && prof[k] == sub[j]) {
                            Path N(i, j);
                            N.add(k);
                            ans.pb(N);
                            vis[k] = true;
                        }
                    }
                }
            }

        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                continue;
            assert(prof[i] != '-');

            if (sub[i] != '-')
                continue;
            vis[i] = true;

            for (int j = 1; j <= n; ++j) {
                if (vis[j])
                    continue;
                if (prof[i] == sub[j]) {
                    Path N(i, -1);
                    N.add(j);
                    ans.pb(N);
                    vis[j] = true;
                }
            }
        }

        vector<pii> A;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (i == j || vis[i] || vis[j])
                    continue;
                if (sub[i] == sub[j])
                    continue;

                vis[i] = vis[j] = true;
                A.pb({i, j});
            }

        for (auto [u, v] : A) {
            Path init = ans[0];
            int st = init.st;
            if (init.mid.size() != 0)
                st = init.mid.back();

            if (prof[init.st] != sub[u])
                swap(u, v);
            init.add(u), init.add(v);
        }

        int Count = 0;
        for (Path v : ans)
            Count += v.Count();

        cout << Count << '\n';
        for (Path v : ans)
            v.print();
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