// Hello I'm Nekan
//
#include <bits/stdc++.h>
#define Nekan "test"
#define fi first
#define se second
#define pb push_back
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define pii pair<int, int>

typedef long double ld;
typedef long long ll;

const int N = 2e5 + 5;
const long long mod = 1e9 + 7; // 998244353;

using namespace std;

long long merge_and_count(vector<int> &arr, int left, int mid, int right) {
    vector<int> left_sub(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> right_sub(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    long long inversions = 0;

    // Merge the two halves and count inversions
    while (i < left_sub.size() && j < right_sub.size()) {
        if (left_sub[i] <= right_sub[j]) {
            arr[k++] = left_sub[i++];
        } else {
            arr[k++] = right_sub[j++];
            inversions += left_sub.size() - i; // Count inversions
        }
    }

    // Copy remaining elements of left_sub
    while (i < left_sub.size()) {
        arr[k++] = left_sub[i++];
    }

    // Copy remaining elements of right_sub
    while (j < right_sub.size()) {
        arr[k++] = right_sub[j++];
    }

    return inversions;
}

long long merge_sort_and_count(vector<int> &arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half
        inversions += merge_sort_and_count(arr, left, mid);

        // Count inversions in the right half
        inversions += merge_sort_and_count(arr, mid + 1, right);

        // Count inversions during the merge
        inversions += merge_and_count(arr, left, mid, right);
    }
    return inversions;
}

long long count_inversions(vector<int> arr) {
    return merge_sort_and_count(arr, 0, arr.size() - 1);
}

struct fenwick {
    vector<int> fw;
    int n;
    fenwick(int x) {
        n = x;
        fw.resize(n + 5);
    }
    void upd(int i, int val) {
        for (; i <= n; i += i & (-i))
            fw[i] += val;
    }
    void upd(int l, int r, int val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    int get(int pos) {
        int ans = 0;
        for (; pos >= 1; pos -= pos & (-pos))
            ans += fw[pos];
        return ans;
    }
    int get(int l, int r) {
        if (l > r)
            return 0;
        int ans = 0;
        ans += get(r) - get(l - 1);
        return ans;
    }

    void clear() {
        for (int i = 1; i <= n; ++i)
            fw[i] = 0;
    }
};

int n, m;
ll inv_count[N];
vector<int> arr[N];

void xuly() {
    cin >> n >> m;
    vector<int> A;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        arr[0].pb(x);
        A.pb(x);
    }

    for (int i = 1; i <= m; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int x;
            cin >> x;
            arr[i].pb(x);
            A.pb(x);
        }
    }

    sort(A.begin(), A.end());

    for (int i = 0; i <= m; ++i) {
        for (int &v : arr[i]) {
            v = lower_bound(A.begin(), A.end(), v) - A.begin() + 1;

            // cout << v << " ";
        }
        // cout << '\n';
        inv_count[i] = count_inversions(arr[i]);
    }

    // cout << "\n\n";

    int maxx = A.size();
    fenwick fw(maxx + 5);

    for (int v : arr[0]) {
        fw.upd(v, 1);
    }

    for (int i = 1; i <= m; ++i) {
        ll res = inv_count[0] + inv_count[i];

        for (int v : arr[i])
            res += fw.get(v + 1, maxx);

        // cout << res << '\n';
        ll ans = res;
        for (int v : arr[i]) {
            res += fw.get(1, v - 1);
            res -= fw.get(v + 1, maxx);
            ans = min(ans, res);
            // cout << res << '\n';
            // cout << fw.get(1, v - 1) << ' ';
            // cout << fw.get(v + 1, maxx) << '\n';
        }

        cout << ans << '\n';
        // cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    if (fopen(Nekan ".inp", "r")) {
        freopen(Nekan ".inp", "r", stdin);
        freopen(Nekan ".out", "w", stdout);
    }
    int t = 1;
    // cin >> t;
    while (t--)
        xuly();
}

// Surely nothing could go wrong.