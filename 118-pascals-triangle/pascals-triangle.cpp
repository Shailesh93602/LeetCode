class Solution {
    int pascal(int i, int j, vector<vector<int>> &memo) {
        if(j == 0 || j == i) return 1;
        if(memo[i][j] != -1) return memo[i][j];
        
        return memo[i][j] = pascal(i-1, j-1, memo) + pascal(i-1, j, memo);
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i=0; i<numRows; i++) {
            vector<int> res;
            for (int j=0; j<i+1; j++) {
                if(j == 0 || i <= 1) res.push_back(1);
                else if(i == j) res.push_back(1);
                else res.push_back(ans[i-1][j] + ans[i-1][j-1]);
            }

            ans.push_back(res);
        }

        return ans;
    }
};