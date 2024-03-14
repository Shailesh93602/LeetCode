class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int n = nums.size();
        
        unordered_map<int, int> freq;
        int sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(sum == goal) count++;
            if(freq.count(sum - goal)) count += freq[sum-goal];
            freq[sum]++;
        }

        return count;
    }
};