#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<string, less<>> set;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set.insert(s);
    }
    for (auto s : set) {
        cout << s << endl;
    }
}
// 64 位输出请用 printf("%lld")
