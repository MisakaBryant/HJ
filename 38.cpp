#include <iostream>
using namespace std;

int main() {
    double H = 0.0;
    cin >> H;
    double s = H;   // 第一次
    for (int i = 0; i < 4; i++) {
        H /= 2;
        s += H * 2;
    }
    cout << s << endl;
    cout << H/2 << endl;
}
// 64 位输出请用 printf("%lld")
