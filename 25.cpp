#include<iostream>
#include<vector>
#include<string>
#include <cstring>
#include<set>
using namespace std;

int main() {
    int I, R;
    while (cin >> I) {
        vector<string> vi;
        while (I--) {
            string a;
            cin >> a;
            vi.emplace_back(a);
        }
        cin >> R;
        set<int> vr;
        while (R--) {
            int b;
            cin >> b;
            vr.insert(b);
        }
        vector<string> res;
        for (auto i : vr) {
            string s = to_string(i);
            int k = 0;
            vector<string> z;
            for (int j = 0; j < vi.size(); ++j) {
                if (strstr(vi[j].c_str(), s.c_str())) {
                    ++k;
                    z.emplace_back(to_string(j));
                    z.emplace_back(vi[j]);
                }
            }
            if (k) {
                res.emplace_back(s);
                res.emplace_back(to_string(k));
                res.insert(res.end(), z.begin(), z.end());
            }
        }
        cout << res.size() << " ";
        for (auto o : res) {
            cout << o << " ";
        }
        cout << endl;
    }
    return 0;
}

// 64 位输出请用 printf("%lld")
