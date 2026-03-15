class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int i: nums) map[i]++;

        vector<pair<int, int>> freq;
        for(const auto pair: map) freq.push_back(pair);

        sort(freq.begin(), freq.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        int n = freq.size();
        for(int i=n-1; i>=n-k; i--) ans.push_back(freq[i].first);

        return ans;
    }
};