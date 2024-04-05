#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    int a;
    cin >> a;
    int b = a/2;
    for (int i = 0; i < a/2 - 1; i++) {
        if (isPrime(b-i) && isPrime(b+i)) {
            cout << b-i << endl;
            cout << b+i << endl;
            return 0;
        }
    }
}
// 64 位输出请用 printf("%lld")