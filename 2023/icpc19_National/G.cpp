#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("G.inp", "r")) {
        freopen("G.inp", "r", stdin);
        freopen("G.out", "w", stdout);
    }

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    long long sumNeg = 0, sumPos = 0;
    vector<long long> neg, pos;
    for (long long& i : a) {
        if (i < 0) {
            sumNeg += i;
            neg.push_back(i);
        } else {
            sumPos += i;
            pos.push_back(i);
        }
    }

    auto solve = [&](vector<long long>& b) -> long long {
        long long res = 1e18;
        long long sum = 0;
        for (long long i : b) {
            sum += i;
        }
        sort(b.begin(), b.end());
        long long n = b.size();
        vector<long long> f(n + 1, 0);
        for (long long i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + b[i - 1];
        }

        auto get = [&](long long l, long long r) -> long long {
            l++, r++;
            if (l > r) {
                return 0;
            }
            return f[r] - f[l - 1];
        };

        for (long long i = 0, j = 0; i < n; ++i) {
            while (j < i && b[j] < b[i] - b[j]) {
                j++;
            }
            res =
                min(res, get(0, j - 1) + 1LL * (i - j + 1) * b[i] - get(j, i) +
                             get(i + 1, n - 1) - (n - i - 1) * b[i]);
        }
        return res;
    };

    long long ans = -sumNeg + solve(pos);

    for (long long& i : neg) {
        i = -i;
    }

    ans = min(ans, solve(neg) + sumPos);
    cout << ans;
}