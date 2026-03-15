class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int i: nums) map[i]++;

        vector<vector<int>> bucket(nums.size()+1);
        for(auto it: map) {
            int first = it.first;
            int second = it.second;
            bucket[second].push_back(first);
        }

        vector<int> ans;
        for(int i=bucket.size() - 1; i>=0; i--) {
            for(int j=bucket[i].size() - 1; j>=0; j--) {
                ans.push_back(bucket[i][j]);

                if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};