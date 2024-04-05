#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        bool has7 = false;
        int num = i;
        while (num > 0) {
            if (num%10 == 7) {
                has7 = true;
                break;
            }
            num /= 10;
        }
        if (i%7==0 || has7) cnt++;
    }
    cout << cnt << endl;
}
// 64 位输出请用 printf("%lld")