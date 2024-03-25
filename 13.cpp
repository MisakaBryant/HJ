#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> v;
    string s;
    while (cin >> s) {
        v.push_back(s);
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[v.size() - 1 - i] << ' ';
    }
}
// 64 位输出请用 printf("%lld")
