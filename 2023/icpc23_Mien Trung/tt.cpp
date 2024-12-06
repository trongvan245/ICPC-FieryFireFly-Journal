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
const long long mod = 1e9 + 7; /// 998244353

using namespace std;

bool c[1000005];
void xuly() {
    int n;
    cin >> n;
    ll t1 = 0, t2 = 0;
    t1= 1ll*(n+1)*n*(2*n+1)/6;
    
    if (t1 % 2) {
        cout<<"NO\n";
        return;
    }
    for(int i=n;i>=1;--i) {
        if (t1 >= 1ll*i*i) {
            t1-= 1ll*i*i;
            c[i]= true;
        }
        c[i]= false;
    }

    if (t1 == 0) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.