class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nums;
        int i=0;
        int j=0;
        while(i<n and j<m) {
            if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n) {
            nums.push_back(nums1[i]);
            i++;
        }
        while(j < m) {
            nums.push_back(nums2[j]);
            j++;
        }
        if((n+m)%2 != 0) {
            return nums[(n+m)/2];
        }
        double val = nums[(n+m)/2];
        return (val+nums[((n+m)/2)-1])/2;
    }
};