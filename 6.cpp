#include <iostream>
using namespace std;

int main() {
    int a = 0;
    cin >> a;
    int k = 2;
    while (a > 1) {
        if (k*k > a) {
            cout << a << ' ';
            break;
        }
        while (a%k == 0) {
            cout << k << ' ';
            a /= k;
        }
        k++;
    }
}
// 64 位输出请用 printf("%lld")
