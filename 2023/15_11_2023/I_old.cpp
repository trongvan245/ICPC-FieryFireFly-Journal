#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    auto ask = [&](vector<int> a) {
        cout << "ASK " << a.size() << ' ';
        for (int i : a) {
            cout << i + 1 << ' ';
        }
        cout << endl;
        vector<int> ans(a.size());
        for (int &i : ans) {
            cin >> i;
            i--;
        }
        sort(ans.begin(), ans.end());
        return ans;
    };


    set<int> ind[1005];
    for (int i = 0; i < n; ++i) {
        ind[0].insert(i);
    }

    int k = log2(n);

    for (int b = k; b >= 0; --b) {
        vector<int> vec;
        for (int i = 0; i < n; i += (1 << (b + 1))) {
            for (int j = i; j < min(n - 1, i + (1 << b)); ++j) {
                vec.push_back(j);
            }
        }
        // for (int i : vec) {
        //     cout << i << ' ';
        // }
        // cout << '\n';
        // continue;
        vector<int> ans = ask(vec);
        for (int i = 0; i < n; i += (1 << (b + 1))) {
            int j = min(n, (i + (1 << b)));
            cout << i << ' ' << j << endl;
            // split ind[i] into ind[i] and ind[j]
            vector<int> rm;

            for (int val : ind[i]) {
                if (!binary_search(ans.begin(), ans.end(), val)) {
                    rm.push_back(val);        
                }
            }
            for (int i : rm) {
                cout << i << ' ';
            }
            cout << endl;
            for (int val : rm) {
                ind[i].erase(val);
                ind[j].insert(val);
            }
        }
    }
    cout << "ANSWER ";
    for (int i = 0; i < n; ++i) {
        cout << *ind[i].begin() << ' ';
    }
    cout << endl;
}