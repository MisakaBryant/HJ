#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){ //每次输入n
        vector<int> dp(n + 1);
        dp[1] = 1; //初始第一个月
        dp[2] = 1; //第二个月
        for(int i = 3; i <= n; i++) //后面的每个月由前面的累加
            dp[i] = dp[i - 1] + dp[i - 2];
        cout << dp[n] << endl;
    }
    return 0;
}
