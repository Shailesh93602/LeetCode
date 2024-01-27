class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSum = nums[0]+nums[nums.size()-1];
        for(int i=1; i<nums.size()-1; i++) {
            maxSum = max(maxSum, nums[i]+nums[nums.size()-i-1]);
        }
        return maxSum;
    }
};