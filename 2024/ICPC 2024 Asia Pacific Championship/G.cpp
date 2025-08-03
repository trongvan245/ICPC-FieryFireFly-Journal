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


char a[5005][3005];
vector<int> question[3005][500];

void xuly() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) cin>>a[i][j];

    
    
    for(int b=1;b<=n;++b) {
        vector<int> cnt(b+1, 0);
        int good= -1;
        for(int j=1;j<=m;++j) {
            char c= a[b][j];
            if (c == '.') continue;
            vector<int> &e= question[j][c];
            for(int i = (int)e.size() - 1; i>=0;--i) {
                int user= e[i];
                ++cnt[user];
                if (cnt[user] >= k) 
                    good= max(good, user);
                
            }
            e.push_back(b);
        }
        if (good != -1) {
            cout << good <<" "<<b <<'\n';
            return;
        }

    }
    cout<<-1;
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