class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        if(n == 0) return 1;
        int start = 1;
        int leftSum = a[0];
        int rightSum = 0;
        for(int i=1; i<n; i++) rightSum += a[i];
        if(rightSum == 0) return 0;
        rightSum -= a[1];
        while(start < n) {
            if(leftSum == rightSum) return start;
            start++;
            if(start >= a.size()) break;
            leftSum += a[start-1];
            rightSum -= a[start];
        }
        // if(leftSum == rightSum) return start;
        return -1;
    }
};