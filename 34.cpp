#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s;
}
// 64 位输出请用 printf("%lld")
