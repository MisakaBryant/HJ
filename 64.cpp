#include <iostream>

using namespace std;

int main() {
    int n = 0;
    string cmd;
    cin >> n >> cmd;
    int ptr = 1;
    int row = 1;
    for (auto c : cmd) {
        if (c == 'U') {
            if (ptr == 1) {
                ptr = n;
                row = min(4, n);
                continue;
            }
            if (row == 1) {
                ptr--;
                continue;
            }
            row--;
            ptr--;
        } else {
            if (ptr == n) {
                ptr = 1;
                row = 1;
                continue;
            }
            if (row == min(4, n)) {
                ptr++;
                continue;
            }
            row++;
            ptr++;
        }
    }
    for (int i = 0; i < min(4, n); i++) {
        cout << ptr - row + i + 1 << ' ';
    }
    cout << endl;
    cout << ptr << endl;
}
// 64 位输出请用 printf("%lld")
