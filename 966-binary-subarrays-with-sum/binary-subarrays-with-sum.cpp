class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> map;

        for(int i=0; i<a.size(); i++) {
            sum += a[i];

            if(sum == k) count++;

            if(map.find(sum-k) != map.end()) count += map[sum-k];

            map[sum]++;
        }

        return count;
    }
};