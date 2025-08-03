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

void xuly() {
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i=1;i<=n;++i) 
    for(int j=1;j<=n;++j) cin>>a[i][j];


    vector<bool> cnt(n+1);
    auto is_row_perm= [&](int r) {
        for(int i=1;i<=n;++i) cnt[i]= false;
        for (int j=1;j<=n;++j) cnt[a[r][j]]= true;

        for(int i=1;i<=n;++i) if (cnt[i] == false) return false;
        return true;
    };
    
    auto is_col_perm= [&](int c) {
        for(int i=1;i<=n;++i) cnt[i]= false;
        for (int i=1;i<=n;++i) cnt[a[i][c]]= true;

        for(int i=1;i<=n;++i) if (cnt[i] == false) return false;
        return true;
    };

    struct three {
        int x, y, val;
    };
    vector<three> ans;

    auto normalize= [&]() {
        for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j) {
            if (is_col_perm(j) && is_row_perm(i)) {
                a[i][j]= (a[i][j] == 1 ) ? 2 : (a[i][j] - 1);
                ans.pb({i, j, a[i][j]});
            }
        }
    };
    normalize();

    
    for(int i=1;i<=n;++i) {
        if (is_row_perm(i)) {
            int pre= a[i][1];
            for(int val=1;val<=n;++val) {
                a[i][1]= val;
                if (!is_row_perm(i) && !is_col_perm(1)) {
                    ans.pb({i, 1, val});
                    break;  
                }
                else a[i][1]= pre;
            }
        }
    }

    
    for(int i=1;i<=n;++i) {
        if (is_col_perm(i)) {
            int pre= a[1][i];
            for(int val=1;val<=n;++val) {
                a[1][i]= val;
                if (!is_row_perm(1) && !is_col_perm(i)) {
                    ans.pb({1, i, val});
                    break;
                }
                else a[1][i]= pre;
            }
        }
    }

    cout << ans.size()<<'\n';
    for(auto[x,y,val] : ans) cout<<x<<" "<<y<<" "<<val<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.