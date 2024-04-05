#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans[4] = {3,2,4,2};
    if (n > 2) {
        cout << ans[n%4] << endl;
    } else {
        cout << -1 << endl;
    }
}
// 64 位输出请用 printf("%lld")