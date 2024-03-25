#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int cnt = 0;
    while (n > 0) {
        if (n%2 == 1) {
            cnt++;
        }
        n /= 2;
    }
    cout << cnt;
}
// 64 位输出请用 printf("%lld")
