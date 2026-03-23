class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        vector<int> curr = intervals[0];
        vector<vector<int>> ans;

        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= curr[1]) curr[1] = max(curr[1], intervals[i][1]);
            else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }

        ans.push_back(curr);

        return ans;
    }
};