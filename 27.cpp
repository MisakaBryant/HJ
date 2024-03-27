#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    string target;
    cin >> target;
    string target_t = target;
    sort(target_t.begin(), target_t.end());
    int k = 0;
    cin >> k;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string t = words[i];
        sort(t.begin(), t.end());
        if (target_t == t && target != words[i]) {
            v.push_back(words[i]);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    if (v.size() >= k) cout << v[k - 1] << endl;
}
// 64 位输出请用 printf("%lld")
