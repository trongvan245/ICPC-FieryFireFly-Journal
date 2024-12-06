#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }

    int n, c, p, q;
    cin >> n >> c >> p >> q;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + (s[i] == 'Y');
    }

    vector<long long> g(n + 1, 0);
    vector<long long> g1(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        g[i] = 1LL * f[i] * q - 1LL * i * p;
    }

    vector<int> ranking(n + 1, 0);

    // (f[i] - f[j - 1]) / (i - j + 1) >= p / q
    // (f[i] - f[j - 1]) * q >= (i - j) * p
    // f[i] * q - i * p >= f[j - 1] * q - (j - 1) * p;

    deque<int> que;

    for (int i = 1, j = 0; i <= n; ++i) {
        ranking[i] = ranking[i - 1];
        while (ranking[j] != ranking[i]) {
            j++;
        }
        if (i - c >= 0) {
            while (!que.empty() && g[que.back()] >= g[i - c]) {
                que.pop_back();
            }
            que.push_back(i - c);
        }

        while (!que.empty() && que.front() <= j - 1) {
            que.pop_front();
        }

        if (!que.empty()) {
            if (g[que.front()] <= g[i]) {
                ranking[i]++;
            }
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << ranking[i] << ' ';
    // }
    // cout << '\n';

    cout << ranking[n];
}