#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_set<int> set;
    for (auto c : s) {
        if (c >= 0 && c < 127) {
            set.insert(c);
        }
    }
    cout << set.size();
}
// 64 位输出请用 printf("%lld")
