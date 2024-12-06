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
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pli;

const ll dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const ll dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007;  /// 998244353
const ll base = 331;

vector<ll> A;
ll n, k, Count, l , r;

void build() {
    A.clear(); Count= 0;
    ll cur= 1;
    
    while(cur <=  1e18 + 1) {
        A.pb(cur);
        cur= cur*3 - 1;
        ++Count;
    }
    
}


void check(ll u, ll v, ll appear) {
    if (u >= l) {
        ll total= appear * (v - u + 1);
        if (total >= k) {
            cout<< u + (k-1)/appear<<'\n';
            k= 0;
            return;
        }
        k-= total;
    }
    else if (v >= l) {
        ll total1= (appear - 1) * (l-u);
        if (total1 >= k) {
            cout<<u + (k-1)/(appear - 1)<<'\n';
            k= 0;
            return;
        }
        k-= total1;

        ll total2= appear * (v - l + 1);
        if (total2 >= k) {
            cout<<l + (k-1) / appear<<'\n';
            k= 0;
            return;
        }
        k-= total2;

    }
    else {
        ll total= (appear-1)*(v - u + 1);
        if (total >= k) {
            cout<< u + (k-1)/(appear-1)<<'\n';
            k= 0;
            return;
        }
        k-= total;
    }
}

bool find(ll id, ll X) {
    // cout<<"\n\n";
    // cout<<id<<" "<<X<<'\n';
    //X
    check(X, X, Count - id + 1);
    if (k <= 0) return true;

    
    if (X == 1) return false;

    //X+1 -> X*2 - 1
    check(X+1, X*2 - 1, Count - id);
    if (k <= 0) return true;

    //X*2 ->X*3-2
    check(X*2, X*3 - 2, Count - id + 1);
    if (k <= 0) return true;


    return false;
}


void gogo() {
    build();
    cin>>n>>k;

    // cout<<n<<" "<<k<<'\n';
    
    // vector<int> M;
    // for(int i=1,cur=1;i<=n;cur= cur + (cur <= i ? i : -i), i++) M.pb(cur);
    // sort(M.begin(), M.end());
    // cout<<M[k-1]<<'\n';

    while(A.back() > n) {
        A.pop_back();
        --Count;
    }


    ll leftmost= (n - A.back()) / 2;
    ll rightmost= (n - A.back() + 1)/2;
    if (n - k + 1 <= rightmost) {
        cout<<A.back()*2 + rightmost - ( n - k + 1) <<'\n';
        return;
    }
    if (n - k + 1 == rightmost + 1) {
        cout<<A.back()<<'\n';
        return;
    }

    l= A.back() - leftmost, r= A.back();
    
    // cout<<l<<" "<<r<<'\n';
    // cout<<Count<<'\n';
    // cout<<'\n';

    for(ll i=0;i+1<Count;++i) {
        if (find(i+1, A[i])) break;
    }

    // cout<<"\n\n";
    // for(int v : M) cout<<v<<'\n';
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);

    }

    ll t;
    cin>>t;
    while(t--)
    gogo();
}
