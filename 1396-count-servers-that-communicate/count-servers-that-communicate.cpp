class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0, n = grid.size(), m = grid[0].size();
        vector<int> ans(m, 0), res(n, -1);

        for(int i=0; i<n; i++) {
            int currCount = 0;

            for(int j=0; j<m; j++) {
                if(grid[i][j]) {
                    currCount++;
                    ans[j]++;
                    res[i] = j;
                }
            }
            
            if(currCount != 1) {
                count += currCount;
                res[i] = -1;
            }
        }
        
        for(int i=0; i<n; i++) count += res[i] != -1 && ans[res[i]] > 1;
        
        return count;
    }
};