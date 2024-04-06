#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int max_l = 0;
    int ans_begin = 0;
    if (a.size() > b.size()) {
        auto t = a;
        a = b;
        b = t;
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (b[j] != a[i]) continue;
            int l = 0;
            while (i + l < a.size() && j + l < b.size() && a[i + l] == b[j + l]) {
                l++;
            }
            if (l > max_l) {
                max_l = l;
                ans_begin = i;
            }
        }
    }
    cout << a.substr(ans_begin, max_l) << endl;
}
// 64 位输出请用 printf("%lld")
