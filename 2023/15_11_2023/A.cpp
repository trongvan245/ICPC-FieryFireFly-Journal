// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long double ld;
typedef long long ll;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

void xuly() {
    int r, c;
    cin>>r>>c;



    int s= r + c;
    int m= r * c;

    int ans= 1;

    for(int i=1;i<=s;++i) ans= 3ll*ans%mod;
    
    for(int i=1;i<=m;++i) ans= 2ll*ans%mod;

    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int t; cin>>t;
    while(t--)
    xuly();
}

// Surely nothing could go wrong.