#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cout << s[s.size() - 1 - i];
    }
}
// 64 位输出请用 printf("%lld")
