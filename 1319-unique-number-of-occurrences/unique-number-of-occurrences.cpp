class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i=0; i<arr.size(); i++) {
            if(map.find(arr[i]) == map.end()) map[arr[i]] = 1;
            else map[arr[i]]++;
        }
        int freq[1002] = {0};
        for(auto &i: map) freq[i.second]++;
        for(int i=0; i<1002; i++) if(freq[i] > 1) return false;
        return true;
    }
};