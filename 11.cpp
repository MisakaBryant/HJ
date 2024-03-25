#include <iostream>
using namespace std;

int main() {
    int i = 0;
    cin >> i;
    if (i == 0) {
        cout << 0;
    }
    while (i > 0) {
        cout << i%10;
        i /= 10;
    }
}
// 64 位输出请用 printf("%lld")
