class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        unordered_map<int, int> map;

        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        
        vector<int> ans;
        for(auto it=map.begin(); it!= map.end(); it++) {
            if(it->second == 1) ans.push_back(it->first);
        }

        return ans;
    }
};