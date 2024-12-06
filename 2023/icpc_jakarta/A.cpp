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
const long long mod = 1e9 + 7; /// 998244353

using namespace std;



int n;
char a[4][4];
int d[4][4];
int dx[8]= {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8]= {-1, 0, 1, 1, 1, 0, -1, -1};

string ans= "ZZZ";

void vet(int i, int j, string res="") {
    res+= a[i][j];
    if (res.size() == 3) {
        ans= min(ans, res);
        return;
    }
    // cout<<res<<" "<<"asdf\n";

    d[i][j]= 1;
    for(int k=0;k<8;++k) {
        int x= i + dx[k], y= j + dy[k];
        if (x <= 0 || x > 3 || y <= 0 || y > 3) continue;
        if (d[x][y]) continue;
        vet(x, y, res);
    }
    d[i][j]= 0;
}

void xuly() {
    int n= 3;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) cin>>a[i][j];


    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j) vet(i, j, "");

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
