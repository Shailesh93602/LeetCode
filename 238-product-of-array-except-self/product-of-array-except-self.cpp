class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProd(n, 0), suffixProd(n, 0);
        prefixProd[0] = nums[0];
        suffixProd[n-1] = nums[n-1];

        for(int i=1; i<n; i++) {
            prefixProd[i] = prefixProd[i-1]*nums[i];
            suffixProd[n-i-1] = suffixProd[n-i]*nums[n-i-1];
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            int pre = 1, post = 1;
            if(i > 0) pre = prefixProd[i-1];
            if(i < n - 1) post = suffixProd[i + 1];

            ans[i] = pre * post;
        }

        return ans;
    }
};