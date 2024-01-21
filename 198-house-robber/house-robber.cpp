class Solution {
public:
    unordered_map<int, int> dp;
    int findMax(vector<int>& nums, int n) {
        if(n == 0) return 0;
        if(n == 1) return nums[n-1];
        if(dp.find(n) != dp.end()) return dp[n];
        return dp[n] = max(nums[n-1] + findMax(nums, n-2), findMax(nums, n-1));
    }
    int rob(vector<int>& nums) {
        return findMax(nums, nums.size());
    }
};