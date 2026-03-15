class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProd(n), rightProd(n);
        
        leftProd[0] = nums[0];
        rightProd[n-1] = nums[n-1];

        for(int i=1; i<n; i++) {
            leftProd[i] = leftProd[i-1]*nums[i];
            rightProd[n-i-1] = rightProd[n-i]*nums[n-i-1];
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(i == 0) ans.push_back(rightProd[i + 1]);
            else if(i == n-1) ans.push_back(leftProd[i - 1]);
            else ans.push_back(leftProd[i - 1] * rightProd[i + 1]);
        }

        return ans;
    }
};