class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int day=1; day<prices.size(); day++){
            if(prices[day] > prices[day-1]){
                profit += prices[day] - prices[day-1];
            }
        }
        return profit;
    }
};