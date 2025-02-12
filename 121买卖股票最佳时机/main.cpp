#include <iostream>
#include <vector>
using namespace std;

// 暴力法
int maxProfit(vector<int>& prices) {
    int n = (int)prices.size(), ans = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, prices[j] - prices[i]);
        }
    }
    return ans;
}

//动态规划
/*
dp[i][0] 表示第i天持有股票所得最多现金 ，这里可能有同学疑惑，本题中只能买卖一次，持有股票之后哪还有现金呢？

其实一开始现金是0，那么加入第i天买入股票现金就是 -prices[i]， 这是一个负数。

dp[i][1] 表示第i天不持有股票所得最多现金

注意这里说的是“持有”，“持有”不代表就是当天“买入”！也有可能是昨天就买入了，今天保持持有的状态

很多同学把“持有”和“买入”没区分清楚。

*/
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}