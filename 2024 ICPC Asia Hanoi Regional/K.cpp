#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll mod= LLONG_MAX;

ll pwd(ll n, ll k) {
    if (k == 0) return 1;
    ll ans= pwd(n, k >> 1);
    if (k&1) return 1LL * ans * ans % mod * n % mod;
    else return 1LL * ans * ans % mod;
}

void solve() {
    int n; cin>>n;
    vector<int> a(n);

    for(int i=0;i<=n;++i) 
        cin>>a[i];

    sort(a.begin(), a.end());

    vector<int> v, c;

    for(int i = 0, d = 0; i < n; ++i) {
        ++d;
        if (i == n - 1 || a[i] != a[i - 1]) {
            v.push_back(a[i]);
            c.push_back(d);
            d = 0;
        }
    }

    int rightside= n, p= 0;
    ll ans= 2*n;
    for(int i=0;i<v.size();++i) {
        rightside= c[i];
        while(p < v.size() && v[p] < 2*v[i]) ++p;

        int is_2= c[i];
        if (v[p] == 2*v[i]) is_2+= c[p];

        if (is_2 >= rightside - is_2) {
            ll res = (n-rightside-c[i])*2 + c[i];
            for(int j=i+1;j<v.size();++j) {
                assert(v[i] != 0);
                int w= (v[j] / v[i]) + 2*(v[j] % v[i] != 0);
                res+= 1ll*c[j]*w;
            }

            ans= min(ans, res);
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    int t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}


