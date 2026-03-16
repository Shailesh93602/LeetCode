class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefCount;
        prefCount[0] = 1;

        int currSum = 0, count = 0;

        for(int num: nums) {
            currSum += num;

            if(prefCount.count(currSum - k)) count += prefCount[currSum - k];

            prefCount[currSum]++;
        }

        return count;
    }
};