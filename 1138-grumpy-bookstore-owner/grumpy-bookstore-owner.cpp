class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        int i;
        
        vector<int> p(n, 0);
        vector<vector<int>> dp(n, {2, 0});
        
        int k = customers[0];
        p[0] = grumpy[0] * customers[0]; 
        dp[0][0] = p[0]; 

        for (i = 1; i < n; i++) {
            k += customers[i]; 
            if (grumpy[i] == 1) p[i] = customers[i] + p[i - 1];

            p[i] = max(p[i - 1], p[i]);
            dp[i][0] = p[i];

            if (i >= minutes) {
                dp[i][1] = dp[i - 1][1] + p[i] - p[i - 1]; 
                dp[i][1] = min(dp[i][1], dp[i - minutes][0]); 
            }
        }

        return k - dp[n - 1][1];
    }
};