class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, maxVal = 0, currVal = 0;

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