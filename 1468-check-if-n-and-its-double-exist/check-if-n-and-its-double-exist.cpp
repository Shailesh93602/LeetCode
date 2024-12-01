class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> map;
        
        for(int i: arr) map[i]++;
        for(int i: arr) {
            if(i == 0 && map[0] == 1) continue;
            if(map.find(i*2) != map.end()) {
                cout <<map[i*2] <<" ";
                return true;
            }
            if(i%2 == 0 && map.find(i/2) != map.end()) {
                cout <<map[i/2];
                return true;
            }
            cout <<endl;
        }

        return false;
    }
};