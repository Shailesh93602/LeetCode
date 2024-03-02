class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int profit = 0;
        int buyPrice = prices[0];
        for(int i=1; i<prices.size()-1; i++) {
            if(buyPrice > prices[i]) {
                buyPrice = prices[i];
            }
            else if (i + 1 < prices.size() && prices[i + 1] < prices[i]) {
                profit += prices[i] - buyPrice;
                buyPrice = prices[i + 1]; 
                i++; 
            }
        }
        if(prices.back() > buyPrice) profit += prices.back()-buyPrice;
        return profit;
    }
};