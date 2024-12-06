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
const int N = 5000 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;



int n, a[N];
int dp[N][N];


void xuly() {
    cin>>n;
    a[0]= n+1;
    for(int i=1;i<=n;++i) 
        cin>>a[i];
    

    dp[1][0]= 1;
    for(int i=2;i<=n;++i) 
    for(int j=1;j<=n;++j) {
        dp[i][j]= dp[i-1][j-1];
        if (a[i] >= a[i-1]) dp[i][j]= (dp[i-1][j-1] + dp[i-1][j])%mod;

        cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
    }

    int ans= 0;
    for(int j=1;j<=n;++j) ans= (ans + dp[n][j])%mod;
    cout<<ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    xuly();
}

// Surely nothing could go wrong.
