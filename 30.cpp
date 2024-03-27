#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int l = s1.size() + s2.size();
    string ans(l, '0');
    vector<char> even((l+1)/2);
    vector<char> odd(l - (l+1)/2);
    int i = 0;
    for (; i < s1.size(); i++) {
        if (i%2 == 0) {
            even[i/2] = s1[i];
        } else {
            odd[i/2] = s1[i];
        }
    }
    for (; i < l; i++) {
        if (i%2 == 0) {
            even[i/2] = s2[i - s1.size()];
        } else {
            odd[i/2] = s2[i - s1.size()];
        }
    }
    sort(even.begin(), even.end(), less<char>());
    sort(odd.begin(), odd.end(), less<char>());
    i = 0;
    for (; i < l; i++) {
        char t = i%2==0 ? even[i/2] : odd[i/2];
        if (t >= 'a' && t <= 'f') {
            t = t - 'a' + 10;
        } else if (t >= 'A' && t <= 'F') {
            t = t - 'A' + 10;
        } else if (t >= '0' && t <= '9') {
            t = t - '0';
        } else {
            ans[i] = t;
            continue;
        }
        int reverse = 0;
        for (int j = 0; j < 4; j++) {
            reverse *= 2;
            reverse += t%2;
            t /= 2;
        }
        ans[i] = reverse < 10 ? '0' + reverse : 'A' + reverse - 10;
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")
