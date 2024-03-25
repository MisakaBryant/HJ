#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int i = 0;
    cin >> i;
    unordered_set<int> set;
    while (i > 0) {
        int t = i%10;
        i /= 10;
        if (set.count(t) == 0) {
            set.insert(t);
            cout << t;
        }
    }
}
// 64 位输出请用 printf("%lld")
