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



int n, k;
int a[105][105];


void check(int i) {
    for(int j=1;j<=n;++j) {
        if (a[i][j]) continue;

        for(int val=1;val<=n;++val) {
            bool cc= true;
            for(int r=1;r<i;++r) if (a[r][j] == val) cc= false;
            for(int c=1;c<j;++c) if (a[i][c] == val) cc= false;

            if (cc) {
                a[i][j]= val;
                break;
            }
        }
    }
}


void xuly() {
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) cin>>a[i][j];

    for(int i=1;i<=n;++i) check(i);

    cout<<"YES\n";

    for(int i=1;i<=n;++i,cout<<'\n')
    for(int j=1;j<=n;++j) cout<<a[i][j]<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    // int t; cin>>t;
    // while(t--)
    xuly();
}

// Surely nothing could go wrong.