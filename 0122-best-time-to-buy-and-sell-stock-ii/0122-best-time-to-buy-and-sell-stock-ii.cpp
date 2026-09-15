class Solution {
private:
    int helper(vector<int> &arr, int n){
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        int profit;
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                // i can buy the stock
                if(buy == 0){
                    profit = max(0 + dp[i+1][0], (-1)*arr[i] + dp[i+1][1]);
                }
                // i can sell the stock
                if(buy==1){
                    profit = max(0 + dp[i+1][1], arr[i] + dp[i+1][0]);
                }

                dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }
    
public:
    int stockBuySell(vector<int> arr, int n){
        return helper(arr, n);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return helper(prices, n);
    }
};