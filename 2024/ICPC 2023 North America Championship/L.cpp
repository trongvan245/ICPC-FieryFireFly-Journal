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
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

bool d[500][500][500];
void xuly() {
    d[1][1][1]= false;

    int LIM= 10;
    for (int i=1;i<=LIM;++i)
    for (int j=i;j<=LIM;++j)
    for (int k=j;k<=LIM;++k) {
        d[i][j][k]= false;
        auto get= [&](int a, int b, int c) {
            vector<int> res;
            res.pb(a); res.pb(b); res.pb(c);
            sort(res.begin(), res.end());
            return res;
        };

        for (int ii=1;ii<i;++ii) {
            vector<int> r1= get(i - ii, i, j);
            vector<int> r2= get(i - ii, i, k);
            
            if (d[r1[0]][r1[1]][r1[2]] == false) d[i][j][k]= true;
            if (d[r2[0]][r2[1]][r2[2]] == false) d[i][j][k]= true;
        }

        
        for (int jj=1;jj<j;++jj) {
            vector<int> r1= get(j - jj, j, i);
            vector<int> r2= get(j - jj, j, k);
            
            if (d[r1[0]][r1[1]][r1[2]] == false) d[i][j][k]= true;
            if (d[r2[0]][r2[1]][r2[2]] == false) d[i][j][k]= true;
        }

        
        for (int kk=1;kk<k;++kk) {
            vector<int> r1= get(k - kk, k, i);
            vector<int> r2= get(k - kk, k, j);
            
            // for (int v : r1) cout<<v << " ";cout<<'\n';
            if (d[r1[0]][r1[1]][r1[2]] == false) d[i][j][k]= true;
            if (d[r2[0]][r2[1]][r2[2]] == false) d[i][j][k]= true;
        }

        cout << i << " " << j << " " << k << " " << (d[i][j][k] ? "true":"false")<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.