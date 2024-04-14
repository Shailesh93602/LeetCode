class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int val = -1;
            bool flag = false;
            for(int j=i+1; j<n; j++) {
                if(nums[j] > nums[i]) {
                    val = nums[j];
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                for(int j=0; j<i; j++) {
                    if(nums[j] > nums[i]) {
                        val = nums[j];
                        break;
                    }
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};