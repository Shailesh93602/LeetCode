class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();

        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];

        for(int i=1; i<n; i++) prefSum[i] = prefSum[i-1]+nums[i];

        unordered_map<int, int> mp; 
        mp[0] = 1;
        for(int i=0; i<n; i++) {
            int posRem = prefSum[i]%k;
            posRem = (posRem + k) % k;
            if(mp.count(posRem)) {
                ans += mp[posRem];
            }  
            mp[posRem]++;
        }

        return ans;
    }
};

// 5
// 4, 5, 0, -2, -3, 1
// 4, 9, 9, 7, 4, 5
// 4, 4, 4, 2, 4, 0
// 0, 1, 2, 2, 4, 5