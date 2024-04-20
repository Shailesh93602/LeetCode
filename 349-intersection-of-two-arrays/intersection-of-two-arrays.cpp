class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a(1000, 0);
        set<int> s;
        for(int i=0; i<nums1.size(); i++){
            a[nums1[i]] = 1;
        }
        for(int i=0; i<nums2.size(); i++){
            if(a[nums2[i]] == 1) s.insert(nums2[i]);
        }
        vector<int> ans;
        for(auto i: s) ans.push_back(i);
        return ans;
    }
};