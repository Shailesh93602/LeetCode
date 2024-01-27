class Solution {
public:
    static bool compare(const pair<int, int>&i, const pair<int, int>&j) {
        return i.second < j.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            if(map.find(nums[i]) != map.end()) map[nums[i]]++;
            else map[nums[i]] = 1;
        }
        vector<pair<int, int>> ans;
        for(auto &i: map) ans.push_back(i);
        sort(ans.begin(), ans.end(), compare); 
        vector<int> res;
        while(k--) {
            res.push_back(ans.back().first);
            ans.pop_back();
        }
        return res;
    }
};