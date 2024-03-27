#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    long long ip;
    cin >> ip;
    long long ans1 = 0ll;
    ans1 += a*256*256*256;
    ans1 += b*256*256;
    ans1 += c*256;
    ans1 += d;
    printf("%lld\n", ans1);
    d = ip%256;
    ip /= 256;
    c = ip%256;
    ip /= 256;
    b = ip%256;
    ip /= 256;
    a = ip;
    printf("%d.%d.%d.%d", a, b, c, d);
}
// 64 位输出请用 printf("%lld")
