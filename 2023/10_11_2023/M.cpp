/* try <3 */
#include <bits/stdc++.h>

using namespace std;

#define task "sol"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((ll)(v).size())
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(), (v).end()

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pli;

const ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const ll dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007;  /// 998244353
const ll base = 331;


vector<int> A;
ld sum[51];

void gogo() {
    int n, k, x;
    cin>>n>>k>>x;

    int Count= 0, cur= 1;
    while(cur <= n) {
        A.pb(cur);
        ++Count;
        cur+= k;
        // if (Count == 2)  break;
    }

    ld Z= 0;
    cout<<fixed<<setprecision(6);
    for(int move= 1; move< 20;++move) {
        ld nxt= (Z + x )/Count;
        ld total= 0;

        cout<<"POUR "<<Count<<" ";
        for(int v : A) {
            cout<<v<<" "<<nxt - sum[v]<<" ";
            total += nxt - sum[v];
            sum[v]= nxt;
        }
        assert(abs(x - total) <= 1e-6);
        cout<<endl;

        Z+= x;

        int vt; cin>>vt;
        for(int i=1;i<=k;++i) {   
            Z-= sum[vt + i - 1];
            sum[vt + i - 1]= 0;
        }
    }

    for(int bottle= Count-1;bottle>=2;--bottle) {

        int c= bottle;
        vector<int> query;
        for(int i=1;i<=n;++i) {
            if (abs(sum[i] - 0) > 1e-7) query.pb(i), --c;
            if (c == 0) break;
        }
        
        cout<<"POUR "<<bottle<<" ";
        for(int v : query) {
            cout<<v<<" "<<(ld)x/bottle<<" ";
            sum[v]+= (ld)x/bottle;
        }
        cout<<endl;

        
        int vt; cin>>vt;
        for(int i=1;i<=k;++i) {   
            Z-= sum[vt + i - 1];
            sum[vt + i - 1]= 0;
        }
    }

    for(int i=1;i<=n;++i) {
        if (abs(sum[i] - 0) > 1e-7) {
            cout<<"FINAL "<<1<<" "<<i<<" "<<x<<endl;
            return;
        }
    }
    cout<<"FINAL "<<1<<" "<<1<<" "<<x<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // if (fopen(task ".inp", "r")) {
    //     freopen(task ".inp", "r", stdin);
    //     freopen(task ".out", "w", stdout);

    // }

    gogo();
}
