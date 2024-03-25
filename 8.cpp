#include <iostream>
#include <map>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    map<int, int> m;
    for (int i = 0;  i < n; i++) {
        int k = 0, v = 0;
        cin >> k >> v;
        m[k] += v;
    }
    for (auto p : m) {
        cout << p.first << ' ' << p.second << endl;
    }
}
// 64 位输出请用 printf("%lld")
