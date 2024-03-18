class Solution {
public:
    static bool compareFirstElement(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compareFirstElement);
        int count = 1;
        int tillMax = points[0][1];
        for(int i=1; i<points.size(); i++) {
            if(points[i][0] > tillMax ) {
                count++;
                tillMax = points[i][1];
            } 
            else {
                tillMax = min(tillMax, points[i][1]);
            }
        }
        return count;
    }
};