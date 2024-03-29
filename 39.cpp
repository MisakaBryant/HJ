#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    int a1, b1, c1, d1;
    int a2, b2, c2, d2;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    scanf("%d.%d.%d.%d", &a1, &b1, &c1, &d1);
    scanf("%d.%d.%d.%d", &a2, &b2, &c2, &d2);
    if (a > 255 || b > 255 || c > 255 || d > 255 || a1 > 255 || b1 > 255 || c1 > 255 || d1 > 255 || a2 > 255 || b2 > 255 || c2 > 255 || d2 > 255 ||
        a < 0 || b < 0 || c < 0 || d < 0 || a1 < 0 || b1 < 0 || c1 < 0 || d1 < 0 || a2 < 0 || b2 < 0 || c2 < 0 || d2 < 0) {
        cout << 1 << endl;
        return 0;
    }
    unsigned mask = a * 256 * 256 * 256 + b * 256 * 256 + c * 256 + d;
    unsigned ip1 = a1 * 256 * 256 * 256 + b1 * 256 * 256 + c1 * 256 + d1;
    unsigned ip2 = a2 * 256 * 256 * 256 + b2 * 256 * 256 + c2 * 256 + d2;
    unsigned t = ~mask;
    if (t == 0 || mask == 0 || (t & (t + 1))) {
        cout << 1 << endl;
        return 0;
    }
    if ((mask & ip1) == (mask & ip2)) {
        cout << 0 << endl;
    } else {
        cout << 2 << endl;
    }
}
// 64 位输出请用 printf("%lld")
