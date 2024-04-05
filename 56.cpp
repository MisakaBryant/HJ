#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i%j == 0) {
                sum += j;
            }
        }
        if (sum == i) cnt++;
    }
    cout << cnt << endl;
}
// 64 位输出请用 printf("%lld")