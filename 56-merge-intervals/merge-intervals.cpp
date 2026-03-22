class Solution {
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<vector<int>> ans;
        vector<int> curr = intervals[0];

        for(int i=1; i<intervals.size(); i++) {
            cout <<curr[0] <<" " <<curr[1] <<endl;
            cout <<intervals[i][0] <<" " <<intervals[i][1] <<endl;
            cout <<endl;
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