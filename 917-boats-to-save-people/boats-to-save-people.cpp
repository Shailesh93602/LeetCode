class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int i=0;
        int j = people.size()-1;
        sort(people.begin(), people.end());
        while(i <= j) {
            if(people[i]+people[j] <= limit) i++;
            j--;
            count++;
        }
        return count;
    }
};