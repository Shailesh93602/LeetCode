class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long int sum = 0;

        for(int i=0; i<k; i++) sum += nums[i];

        int left = 0;
        long long int maxSum = sum;

        for(int right=k; right<nums.size(); left++, right++) {
            sum += nums[right];
            sum -= nums[left];

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};