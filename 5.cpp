#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0;
    for (int i = 2; i < s.size(); i++) {
        a *= 16;
        a += (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 10 : s[i] - '0';
    }
    cout << a << endl;
}
// 64 位输出请用 printf("%lld")
