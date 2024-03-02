class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        int i = 0;
        for(int j=0; j<nums.size(); j++) {
            if(map[nums[j]] < 2) {
                nums[i++] = nums[j];
                map[nums[j]]++;
            }
        }
        return i;
    }
};