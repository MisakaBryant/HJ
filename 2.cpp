#include <iostream>
#include <ostream>
#include <string>
using namespace std;

int main() {
    string in;
    char c;
    getline(cin, in);
    cin >> c;
    int ans = 0;
    for (auto ch : in) {
        if (c == ch) ans++;
        if (c >= 'a' && c <= 'z') {
            if (ch == c - 'a' + 'A') ans++;
        }
        if (c >= 'A' && c <= 'Z') {
            if (ch == c - 'A' + 'a') ans++;
        }
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")
