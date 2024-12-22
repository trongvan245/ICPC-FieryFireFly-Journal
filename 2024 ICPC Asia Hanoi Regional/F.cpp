#include <bits/stdc++.h>

using namespace std;

void solve(int n, string s) {
    vector<int> A= {1, (int)1e9, (int)1e9 - 1, 2, 3, 4, 5, 6, 7};

    for(int i=max(1, n-10); i<= min((int)1e9, n + 10); ++i) {
        A.push_back(i);
    }

    sort(A.begin(), A.end());

    for(int a : A)
    for(int b : A)
        if (a < b) {
            if (s == "fizzbuzz") {
                if (n % a == 0 && n % b == 0) {
                    cout<<a<<" "<<b<<'\n';
                    return;
                }
            }
            else if (s == "fizz") {
                if (n % a == 0 && n % b != 0) {
                    cout<<a<<" "<<b<<'\n';
                    return;
                }
            }
            else if (s == "buzz") {
                if (n % b == 0 && n % a != 0) {
                    cout<<a<<" "<<b<<'\n';
                }
            }
            else {
                if (n % a != 0 && n % b != 0) {
                    cout<<a<<" "<<b<<'\n';
                    return;
                }
            }
        }
    cout<<-1<<" "<<-1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    int t; cin>>t;

    while(t--) {
        int n;
        cin>>n;
        string s; cin>>s;
        solve(n, s);
    }
}