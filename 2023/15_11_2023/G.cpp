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

const int N = 1e5 + 5;
const long long mod = 1e9 + 7; /// 998244353

using namespace std;


int n;

void xuly() {
    cin>>n;
    string s= to_string(n);

    int Count= 0;


    while(n != 1) {
        string s= to_string(n);
        bool all10= true;
        for(int i=1;i<s.size();++i) if (s[i] != '0') all10= false;
        if (all10) {
            --n;
            ++Count;
            continue;
        }
        if (s[0] != '1') {

            bool c= false;
            for(int i=1;i<s.size();++i) if (s[i] == '1') {
                swap(s[0], s[i]);
                swap(s[i], s.back());
                ++Count;

                n= stoi(s);
                c= true;
                break;
            }
            if (c) continue;

            for(int i= (int)s.size() - 1;i>=1;--i) if (s[i] != '0') {
                if (i + 1 != s.size()) {
                    swap(s[i], s.back());
                    ++Count;
                }
                Count+= (s.back() - '1') + 1;
                s.back()= '1';
                swap(s[0], s.back());
                n= stoi(s);
                break;
            }
            // cout<<Count<<'\n';
            
        }
        else {
        
            if (s.back() == '0') {
                for(int i=1;i<s.size();++i) if (s[i] != '0') {
                    swap(s[i], s.back());
                    break;
                }
                ++Count;
            }
            else {
                Count+= s.back() - '0';
                s.back() = '0';
            }
            n= stoi(s);
        }
    }
    cout<<Count<<'\n';
    return;
    int cur= 1, digit= 1, res= 0;
    while(cur * 10 <= n) {
        res+= digit - 1  + (digit*9 - 1) + 1;
        cur*= 10; ++digit;

        // cout<<digit<<" "<<res<<'\n';
    }

    // cout<<res<<'\n';

    if (cur == 1) {
        cout<<n-1<<'\n';
        return;
    }

    if (s[0] == '1') {
        int swap= 0, ss= 0;
        for(int i=1;i<s.size();++i) if (s[i] != '0') ++swap, ss+= s[i] - '0';

        if (swap != 0 && s.back() != '0') --swap;

        res+= swap + ss;
        cout<<res<<'\n';
    }
    else {
        bool check= true;
        for(int i=1;i<s.size();++i) if (s[i] != '0') check= false;

        if (check) {
            if (s[0] == '2') res+= (digit - 1)*10;
            else res+= (s[0] - '0' - 1) + (digit-1)*10;
            cout<<res<<'\n';
            return;
        }


        int swap= 0, ss= 0;
        bool one= false;
        for(int i=0;i<s.size();++i) {
            if (s[i] != '0') ++swap, ss+= s[i] - '0';
            if (s[i] == '1') one= true;
        }

        if (one || s.back() != '0') --swap;
        res+= swap + (ss - 1);

        cout<<res <<'\n';
    }


    // cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }

    int t; cin>>t;
    while(t--)
    xuly();
}

// Surely nothing could go wrong.