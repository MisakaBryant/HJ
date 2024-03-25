#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    set<int, less<>> s;
    for (int i = 0; i < n; i++) {
        int t = 0;
        cin >> t;
        s.insert(t);
    }
    for (auto i : s) {
        cout << i << endl;
    }
}
// 64 位输出请用 printf("%lld")
