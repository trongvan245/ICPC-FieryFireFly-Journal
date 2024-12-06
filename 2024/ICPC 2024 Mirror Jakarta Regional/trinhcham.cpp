#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "J";
// Số test kiểm tra
const int NTEST = 1000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên
// số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL % (h - l + 1);
}

int d[1005][1005];
int main() {
    srand(time(NULL));
    // for (int i = 0; i <= 1000; ++i)
    //     d[0][i] = d[i][0] = 1;
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        ofstream inp((NAME + ".inp").c_str());
        int n = 5, m = 4;
        inp << n << " " << m << '\n';
        int maxx = (1 << 4) - 1;
        for (int i = 1; i <= n; ++i)
            inp << Rand(1, maxx) << " ";
        inp << '\n';
        for (int i = 1; i <= m; ++i)
            inp << Rand(1, maxx) << " ";
        inp << '\n';

        // Code phần sinh test ở đây
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_full.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}