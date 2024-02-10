class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;
        int maxArr[prices.size()];
        maxArr[prices.size()-1] = prices[prices.size()-1];
        for(int i=prices.size()-2; i>=0; i--) {
            maxArr[i] = max(maxArr[i+1], prices[i]);
        }
        for(int i=0; i<prices.size()-1; i++) {
            profit = maxArr[i+1]-prices[i];
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};