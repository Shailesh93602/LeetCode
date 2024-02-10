class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 1;
        int step = nums[0];
        int maxPos = nums[0];
        for(int i=1; i<nums.size()-1; i++) {
            maxPos = max(maxPos, nums[i]+i);
            step--;
            if(step == 0){
                count++;
                step = maxPos-i;
            }
        }
        if(nums.size() == 1) return 0;
        return count;
    }
};