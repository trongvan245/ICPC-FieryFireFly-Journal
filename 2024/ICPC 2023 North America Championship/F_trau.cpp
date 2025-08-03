// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll          long long
#define ull         unsigned long long
#define ld          long double
#define for_(n)     for(ll i=0; i<n; i++)
#define for__(a,b)  for(ll i=a; i<b; i++)
#define _for(i,a,b) for(ll i=a; i<b; i++)
#define mp          make_pair
#define fi          first
#define se          second
#define pb          push_back
#define pii         pair<int, int>
#define pll         pair<long long, long long>
#define el          "\n"
#define debug(x)    if(ENABLE_DEBUG) cerr << "[debug] " << #x << " : " << x << endl;
#define M_PI        3.14159265358979323846

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;

typedef tree<int,null_type, greater<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const long long MOD=  2e9;
bool ENABLE_DEBUG = false;

template<class T, class P>
ostream& operator<<(ostream& os, const pair<T,P> &a) {os << "{" << a.first << ";" << a.second << "}"; return os;}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &a) {for(auto it: a) os << it << " "; return os;}
template<class T>
ostream& operator<<(ostream& os, const deque<T> &a) {for(auto it: a) os << it << " "; return os;}
template<class T>
ostream& operator<<(ostream& os, const set<T> &a) {for(auto it: a) os << it << " "; return os;}
template<class T>
ostream& operator<<(ostream& os, const multiset<T> &a) {for(auto it: a) os << it << " "; return os;}

template<class T, class P>
pair<T, P> operator+(const pair<T, P> & a, const pair<T, P> &b) {return mp(a.fi+b.fi, a.se+b.se);}
template<class T, class P>
pair<T, P> operator-(const pair<T, P> & a, const pair<T, P> &b) {return mp(a.fi-b.fi, a.se-b.se);}

template<class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b) 
{assert(a.size() == b.size()); vector<T> re; for_(a.size()) re.pb(a[i] + b[i]); return re;}
template<class T>
vector<T> operator-(const vector<T> &a, const vector<T> &b) 
{assert(a.size() == b.size()); vector<T> re; for_(a.size()) re.pb(a[i] - b[i]); return re;}
template<class T, class P>
vector<T> operator*(const vector<T> &a, const P &b) {vector<T> re; for_(a.size()) re.pb(a[i]*b); return re;}
template<class T, class P>
vector<T> operator*(const P &b, const vector<T> &a) {vector<T> re; for_(a.size()) re.pb(a[i]*b); return re;}

ll gcd(ll a, ll b) { return b==0? a : gcd(b,a%b); }
ll lcm(ll a, ll b) { return a/(gcd(a,b))*b; }

ll pow_mod(ll x, ll y, ll mod) { //mod<3.10^9
    ll ans=1;
    while(y>0) {
        if(y%2==1) ans=ans*x%mod;
        y=y>>1;
        x=x*x%mod;
    }
    return ans%mod;
}

bool check(pii r1, pii r2, pii r3, pii r4) {
    if(r1.fi != r2.fi) return false;

    int W = r1.fi;
    int H = r1.se + r2.se;

    if(r3.fi == W) {
        if(r3.se + H == r4.se && r4.fi + W == r4.se) return true;
    }

    if(r4.fi == W) {
        if(r4.se + H == r3.se && r3.fi + W == r3.se) return true;
    }

    if(r3.se == H) {
        if(r3.fi + W == r4.fi && r4.se + H == r4.fi) return true;
    }

    if(r4.se == H) {
        if(r4.fi + W == r3.fi && r3.se + H == r3.fi) return true;
    }

    if(r3.fi == W && r4.fi == W && W == H + r3.se + r4.se) return true;
    if(r3.se == H && r4.se == H && W + r3.fi + r4.fi == H) return true;

    if(r3.fi + r4.fi == W && r3.se == r4.se && r3.se + H == W) return true;
    if(r3.se + r4.se == H && r3.fi == r4.fi && r3.fi + W == H) return true;

    return false;
}

void solve(int ith) {
    vector<pii> r(4);
    for_(4) cin >> r[i].fi >> r[i].se;

    int cnt = 0;

    _for(a, 0, 2) {
        _for(b, 0, 2) {
            _for(c, 0, 2) {
                _for(d, 0, 2) {
                    vector<pii> cr = r;
                    for(int kk = 0; kk < 24; kk++) {
                        if(check(cr[0], cr[1], cr[2], cr[3])) {
                            cout << 1;
                            return;
                        }
                        cnt++;
                        next_permutation(cr.begin(), cr.end());
                    }
                    swap(r[3].fi, r[3].se);
                }
                swap(r[2].fi, r[2].se);
            }
            swap(r[1].fi, r[1].se);
        }
        swap(r[0].fi, r[0].se);
    }

    // debug(cnt);

    cout << 0;
}


int main() {
    // clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.ans", "w", stdout);
    ENABLE_DEBUG = true;
    #endif


    int t = 1;
    // cin >> t;
    for_(t)
        solve(i);


    // cerr << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}