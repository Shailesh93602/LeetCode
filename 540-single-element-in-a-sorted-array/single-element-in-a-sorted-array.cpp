class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorVal = nums[0];
        for(int i=1; i<nums.size(); i++) xorVal ^= nums[i];
        return xorVal;
    }
};