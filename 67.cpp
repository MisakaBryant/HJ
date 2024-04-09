#include <iostream>
#include <vector>

using namespace std;

vector<char> symbols = {'+','-','*','/'};

double cal(double a, double b, char symbol) {
    switch (symbol) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) return 0x3f3f3f3f;
            return a / b;
        default:
            return 0;
    }
}

bool dfs(vector<double>& nums) {
    if (nums.size() == 1) {
        return nums[0] == 24;
    }
    bool ret = false;
    for (int i = 0; i < nums.size(); i++) {
        vector<double> t1 = nums;
        int a = t1[i];
        t1.erase(t1.begin()+i);
        for (int j = 0; j < t1.size(); j++) {
            vector<double> t2 = t1;
            int b = t2[j];
            t2.erase(t2.begin()+j);
            for (char sy : symbols) {
                vector<double> t3 = t2;
                t3.push_back(cal(a, b, sy));
                ret |= dfs(t3);
            }
        }
    }
    return ret;
}

int main() {
    vector<double> nums(4);
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
    cout << (dfs(nums) ? "true" : "false") << endl;
}
// 64 位输出请用 printf("%lld")
