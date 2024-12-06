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

const int N = 5000 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;


int r, c, ans;
vector<int> qr[N], qc[N];
map<vector<int>, vector<int>> M;


int maskC[N];
void vet(int x) {
    if (x == r) {
        maskC[x]= 0;
        
        for(int bit=0;bit<c;++bit) {
            vector<int> cur;
            int cnt= 0;
            for(int i=0;i<=r;++i) {
                if (BIT(maskC[i], bit)) ++cnt;
                else if (cnt) {
                    cur.pb(cnt);
                    cnt= 0;
                }
            }

            if (cur != qc[bit]) return;
        }
        ++ans;
        return;
    }
    

    for(int v : M[qr[x]]) {
        maskC[x]= v;
        vet(x + 1);
    }
}



void xuly() {
    cin>>r>>c;
    for(int i=0;i<r;++i) {
        int k; cin>>k;

        while(k--) {
            int x; cin>>x;
            qr[i].pb(x);
        }
    }

    
    for(int i=0;i<c;++i) {
        int k; cin>>k;

        while(k--) {
            int x; cin>>x;
            qc[i].pb(x);
        }
    }


    for(int mask=0;mask<(1<<c);++mask) {
        vector<int> e;
        int cnt= 0;
        for(int i=0;i<=c;++i) {
            if (BIT(mask, i)) cnt++;
            else if (cnt) {
                e.pb(cnt);
                cnt= 0;
            }
        }

        // for(int v : e) cout<<v<<" ";
        // cout<<'\n';
        // cout<<mask<<'\n';

        // cout<<"\n\n";
        M[e].pb(mask);
    }


    vet(0);

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