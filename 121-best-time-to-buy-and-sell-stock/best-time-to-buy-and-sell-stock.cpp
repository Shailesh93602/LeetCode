class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxVal = 0, lastMinPrice = prices[0];

        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > lastMinPrice) {
                maxVal = max(maxVal, prices[i] - lastMinPrice);
            } else lastMinPrice = prices[i];
        }

        return maxVal;
    }
};