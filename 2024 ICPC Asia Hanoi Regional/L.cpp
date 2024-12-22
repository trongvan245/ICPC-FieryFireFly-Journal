#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 998244353;

ll pwd(ll n, ll k) {
    if (k == 0) return 1;
    ll ans = pwd(n, k >> 1);
    if (k & 1) {
        return 1LL * ans * ans % mod * n % mod;
    } else {
        return 1LL * ans * ans % mod;
    }
}

ll inv(ll a) {
    return pwd(a, mod-2);
}

#define pii pair<ll, ll>

multiset<pii> train;
void solve() {
    ll s, q;
    cin>>s>>q;
    
    ll ans= 0;

    auto add= [&](ll w, ll l) {
        train.insert({l, w});
        ans= (ans + 1ll*w*inv(l))%mod;
    };
    auto del= [&](ll w, ll l) {
        train.erase(train.find({l, w}));
        ans= (ans + mod*mod - 1ll*w*inv(l))%mod;
    };

    while(q--) {
        char x; ll w, l;
        cin>>x>>w>>l;
        if (x == '+') add(w, l);
        else del(w, l);

        if (train.size() == 0) {
            cout<<0<<'\n';
            continue;
        }
        pii e= *train.begin();

        ll S_vmin= 1ll*s*inv(e.first)%mod;
        
        cout<<(ans + S_vmin)%mod<<'\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    ll t= 1;
    while(t--) {
        solve();
    }
    return 0;
}