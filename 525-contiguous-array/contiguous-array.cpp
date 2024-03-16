class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n);
        if(nums[0] == 1) leftSum[0] = 1;
        else leftSum[0] = -1;
        for(int i=1; i<n; i++) {
            if(nums[i] == 1) leftSum[i] = leftSum[i-1]+1;
            else leftSum[i] = leftSum[i-1]-1;
        } 
        int maxCount = 0;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++) {
            if(leftSum[i] == 0) maxCount = max(maxCount, i+1);
            else if(map.find(leftSum[i]) == map.end()) map[leftSum[i]] = i;
            else maxCount = max(maxCount, i-map[leftSum[i]]);
        }
        return maxCount;

    }
};