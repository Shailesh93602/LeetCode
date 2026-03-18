class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, maxVal, currVal;

        for(int i=0; i<nums.size()-1; i++) {
            maxVal = max(maxVal, (i + nums[i]));

            if(i == currVal) {
                ans++;
                currVal = maxVal;
            }
        }

        return ans;
    }
};