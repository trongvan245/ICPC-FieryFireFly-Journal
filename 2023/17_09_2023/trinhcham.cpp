#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "D";
const string TEST = "test";
// Số test kiểm tra
const int NTEST = 100;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
// #define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên
// số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rand() * 1LL * rand() % (h - l + 1);
}

int main() {
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        ofstream inp((TEST + ".inp").c_str());
        int n = 5;
        int m = Rand(1, n);
        int k = Rand(1, n);
        int c = rand() % 10;
        int d = rand() % 100;
        inp << n << " " << k << " " << m << " " << c << " " << d << '\n';

        for (int i = 1; i <= n; ++i)
            inp << rand() % 100 << " ";

        // Code phần sinh test ở đây
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + TEST + ".out " + TEST + ".ans").c_str()) != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}