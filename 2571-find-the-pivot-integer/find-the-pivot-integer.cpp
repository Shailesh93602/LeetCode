class Solution {
public:
    int pivotInteger(int n) {
        int leftSum[n];
        int rightSum[n];
        leftSum[0] = 1;
        rightSum[n-1] = n;
        for(int i=1; i<n; i++) {
            leftSum[i] = leftSum[i-1]+i+1;
        }
        for(int i=n-2; i>=0; i--) {
            rightSum[i] = rightSum[i+1]+i+1;
        }
        for(int i=n-1; i>=0; i--) {
            if(leftSum[i] == rightSum[i]) return i+1;
        }
        return -1;
    }
};