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
#define zs(v) ((int)(v).size())
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ld, ld> pldld;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007;  /// 998244353
const ll base = 331;


bool lineInPoylgon(int a, int b, int c, vector<pldld> Points) {
    bool c1= false, c2= false;
    for(auto v : Points) {
        if (a*v.fi + b*v.se - c < 0) c1= true;
        if (a*v.fi + b*v.se - c > 0) c2= true;
    }

    return (c1 && c2);
}

bool pointInLines(pldld e, int a, int b, int c1, int c2) {
    bool t1= (a*e.fi + b*e.se - c1 < 0);
    bool t2= (a*e.fi + b*e.se - c2 > 0);

    bool s1= (a*e.fi + b*e.se - c1 > 0);
    bool s2= (a*e.fi + b*e.se - c2 < 0);

    return (t1&&t2)||(s1&&s2);
}


int k;
pldld p[10];
vector<pldld> Points;


void gogo() {
    int a, b, c1, c2;
    cin>>a>>b>>c1>>c2;

    cin>>k;
    Points.clear();
    for(int i=1;i<=k;++i) {
        cin>>p[i].fi>>p[i].se;
        Points.pb(p[i]);
    }
    p[k+1]= p[1];

    for(int i=1;i<=k;++i) {
        pldld e1= p[i], e2= p[i+1];
        pldld e= {(e1.fi + e2.fi)/2.0, (e1.se + e2.se)/2.0};

        Points.pb(e);
    }

    if (lineInPoylgon(a, b, c1, Points) || lineInPoylgon(a, b, c2, Points)) {
        cout<<"YES\n";
        return;
    }

    for(auto e : Points) {
        if (pointInLines(e, a, b, c1, c2)) {
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);

    }
    int t; cin>>t;
    while(t--) gogo();
}
