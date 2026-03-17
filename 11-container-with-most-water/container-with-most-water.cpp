class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, n = height.size();
        int left = 0, right = n-1;

        while(left < right) {
            ans = max(ans, min(height[left], height[right]) * (right - left));

            if(height[left] < height[right]) left++;
            else if(height[left] > height[right]) right--;
            else left++;
        }

        return ans;
    }
};