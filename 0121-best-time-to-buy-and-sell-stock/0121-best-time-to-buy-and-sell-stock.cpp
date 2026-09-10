class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int Buy = INT_MAX;
        int profit = 0;
        for(int i=0; i<n; i++){
            Buy=min(Buy, prices[i]);
            profit= max(profit, prices[i]-Buy);
        }
        return profit;
    }
};