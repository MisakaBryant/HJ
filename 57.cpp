#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int i = a.size();
    int j = b.size();
    int l = 0;
    if (i > j) {
        l = i;
        for (int n = 0; n < i-j; n++) {
            b = '0' + b;
        }
    } else {
        l = j;
        for (int n = 0; n < j-i; n++) {
            a = '0' + a;
        }
    }
    b = '0' + b;
    a = '0' + a;
    for (int n = l; n > 0; n--) {
        int t = a[n] - '0' + b[n] - '0';
        a[n] = t%10 + '0';
        a[n - 1] += t/10;
    }
    if (a[0] == '0') {
        cout << a.substr(1) << endl;
    } else {
        cout << a << endl;
    }
}
// 64 位输出请用 printf("%lld")