class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n, -1);

        for(int i=0; i<n; i++) {
            int j = 0;
            while(j < m) {
                if(nums1[i] == nums2[j]) break;

                j++;
            }

            int num = nums2[j];
            while(j < m) {
                if(nums2[j] > num) {
                    ans[i] = nums2[j];
                    break;
                }

                j++;
            }
        }

        return ans;
    }
};