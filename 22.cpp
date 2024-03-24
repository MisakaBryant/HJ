#include <iostream>
using namespace std;

int main() {
    int n = 0;
    while (cin >> n) {
        if (n == 0) break;
        cout << n / 2 << endl;
    }
}
// 64 位输出请用 printf("%lld")