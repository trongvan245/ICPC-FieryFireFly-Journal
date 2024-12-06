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
const int N = 2000 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;



int n, p[N], skip[N], a[N], d[N];
vector<pii> A;
int dp[N], nDp[N];
int tv[N];


void xuly() {
    cin>>n;
    n*= 2;
    for(int i=1;i<=n;++i) {
        cin>>a[i];
        p[a[i]]= i;
    }

    A.pb({0 , 0});
    int L= n;
    for(int i=n;i>=1;--i) {
        if (skip[i]) continue;

        for(int j=p[i];j<=L;++j) skip[a[j]]= 1;
        A.pb({L - p[i] + 1, p[i]});
        L= p[i]-1;

        if (L == 0) break;
    }

    for(int i=1;i<=n;++i) dp[i]= 0;
    dp[0]= 1;

    for(int i=1;i<A.size();++i) {
        auto [L, num]= A[i];

        for(int j=L;j<=n/2;++j) {
            if (dp[j] || nDp[j]) continue;
            nDp[j]= dp[j-L];
            if (nDp[j]) {
                tv[j]= i;
            }
        }

        for(int j=0;j<=n/2;++j) {
            dp[j]= nDp[j];
        }
    }


    int index= n/2;

    if (tv[index] == 0) {
        cout<<-1;
        return;
    }

    while(tv[index]) {
        auto [L, pos]= A[tv[index]];
        for(int i=pos;i<=pos+L-1;++i) {
            cout<<a[i]<<" ";
            d[i]= 1;
        }

        index-= L;
    }

    cout<<'\n';
    for(int i=1;i<=n;++i) if (!d[i]) cout<<a[i]<<" ";

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
