// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan ""
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


int n;
int res[N];
vector<int> query[20];


void xuly() {
    cin>>n;

    for(int mask=0;mask<n;++mask) {
        for(int bit= 0;bit<=10;++bit) 
            if (mask & (1<<bit)) query[bit].pb(mask);
        
    }


    for(int bit=10;bit>=0;--bit) {
        int k= query[bit].size();
        if (query[bit].empty()) continue;
        cout<<"ASK "<<k<<" ";
        for(int mask : query[bit]) cout<<mask + 1<<" ";
        cout<<endl;


        for(int i=1;i<=k;++i) {
            int x; cin>>x;
            res[x]^= 1<<bit;
        }
    }

    cout<<"ANSWER ";
    for(int i=1;i<=n;++i) cout<<res[i] + 1<<" ";
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // if (fopen(Nekan ".inp", "r")) {
    //     freopen(Nekan ".inp", "r", stdin);
    //     freopen(Nekan ".out", "w", stdout);
    // }
    xuly();
}

// Surely nothing could go wrong.