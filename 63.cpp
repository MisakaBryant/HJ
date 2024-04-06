#include <iostream>
using namespace std;

int main() {
    string dna;
    int n = 0;
    cin >> dna >> n;
    int l = 0, r = 0;
    int ans_begin = 0;
    int CG_cnt = 0;
    int CG_max = 0;
    while (r < dna.size()) {
        if (dna[r] == 'C' || dna[r] == 'G') CG_cnt++;
        if (r - l >= n - 1) {
            if (CG_cnt > CG_max) {
                ans_begin = l;
                CG_max = CG_cnt;
            }
            if (dna[l] == 'C' || dna[l] == 'G') CG_cnt--;
            l++;
        }
        r++;
    }
    cout << dna.substr(ans_begin, n) << endl;
}
// 64 位输出请用 printf("%lld")
