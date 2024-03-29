#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> w(n);
    vector<int> cnt(n);
    unordered_set<int> hashSet;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cnt[i];
    }
    vector<int> nums(n, 0);
    hashSet.insert(0);
    for (int i = 0; i < n; i++) {
        unordered_set<int> t;
        for (int k = 1; k < cnt[i] + 1; k++) {
            for (auto j: hashSet) {
                t.insert(j + w[i]*k);
            }
        }
        hashSet.insert(t.begin(), t.end());
    }
    cout << hashSet.size() << endl;
}
// 64 位输出请用 printf("%lld")
