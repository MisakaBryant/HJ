#include <iostream>
using namespace std;

int main() {
    int a;
    while (cin >> a) { // 注意 while 处理多个 case
        int cnt = 0;
        while (a > 0) {
            if (a%2) cnt++;
            a /= 2;
        }
        cout << cnt << endl;
    }
}
// 64 位输出请用 printf("%lld")
