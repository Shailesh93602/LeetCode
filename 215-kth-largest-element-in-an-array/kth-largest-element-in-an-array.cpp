class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int &i: nums) i *= -1;

        priority_queue<int> pq;

        for(int i: nums) {
            pq.push(i);

            if(pq.size() > k) pq.pop();
        }

        return pq.top() * -1;
    }
};