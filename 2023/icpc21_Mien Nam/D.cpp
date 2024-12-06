// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan ""
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


int type[2][305];



void xuly() {
    cin>>n>>l;
    for(int i=1;i<=n;++i) {
        string x, y;
        cin>>a[i]>>x>>y;
        
        if (x == 'none') b[i].fi= -1;
        else if (x == 'in') b[i].fi= 0;
        else b[i].fi= 1;

        if (y == 'none') b[i].se= -1;
        else if (y == 'in') b[i].se= 0;
        else b[i].se= 1;
    }

    for(int i=1;i<=n;++i) {
        
    }
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

//Surely nothing could go wrong.