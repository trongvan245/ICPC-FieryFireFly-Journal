// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((ll)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<ll, ll>

typedef long double ld;
typedef long long ll;

const ll N = 2e5 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

void xuly() {
    ll n; cin >> n;
    vector<pii> a(n);

    for(auto &[x, y] : a) cin >> x >> y;

    

    auto cal= [&](ll A, ll B) {
        vector<vector<ld>> dist(n + 1, vector<ld>(n + 1));

        auto get_dist= [&](pii a, pii b) {
            ll x= a.fi - b.fi;
            ll y= a.se - b.se;
            return x * x + y * y;
        };

        ld w= sqrt(A * A + B * B);
        for (ll i = 0; i < n; ++i)
        for (ll j = i + 1; j < n; ++j) {
            //tim duong thang di qua diem thu i
            ll c= -(a[i].fi * A + a[i].se * B);

            ld dx= (a[j].fi * A + a[j].se * B + c) / w;
            dx= abs(dx);
            ld dy= sqrt(get_dist(a[i], a[j]) - dx * dx);
            dist[i][j]= dist[j][i]= dx + dy;
        }

        // cout << A <<" "<<B<<'\n';
        // for(ll i=0;i<n;++i)
        // for(ll j=i+1;j<n;++j) cout<<i<<" "<<j<<" "<<dist[i][j]<<'\n';

        // cout<<'\n';
        
        vector<vector<ld>> dp(1 << n, vector<ld>(n, 1e9));
        for (ll i = 0; i < n; ++i) dp[1 << i][i]= 0;

        for (ll mask = 1; mask < (1 << n); ++mask) {
            for (ll i = 0 ; i < n; ++i) {
                if (!BIT(mask, i)) continue;

                for (ll j = 0; j < n; ++j) if (!BIT(mask, j)) 
                    dp[mask + (1 << j)][j]= min(dp[mask + (1 << j)][j], dp[mask][i] + dist[i][j]);
                
            }
        }

        ld ans= 1e9;
        for (ll i = 0; i < n; ++i) ans = min(ans, dp[(1 << n) - 1][i]);

        return ans;
    };

    ld ans= 1e9;
    for (ll i = 0 ; i < n; ++i)
    for (ll j = i + 1; j < n; ++j) {
        ll A= a[j].se - a[i].se, B= -a[j].fi + a[i].fi;
        ans= min(ans, cal(A, B));
    }

    cout << fixed<<setprecision(10)<< ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    ll t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.