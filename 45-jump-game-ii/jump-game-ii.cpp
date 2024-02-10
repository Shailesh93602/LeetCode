class Solution {
public:
    int findRecursive(vector<int> arr, int n) {
        int val = -1;
        for(int i=0; i<n; i++) {
            if(arr[i]+i >=n) {
                val = i;
                break;
            }
        }
        return val;
    }
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int count = 1;
        int val = findRecursive(nums, nums.size()-1);
        while(val > 0) {
            count++;
            val = findRecursive(nums, val);
        }
        if(val == -1) return val;
        return count;
    }
};