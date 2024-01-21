class Solution {
public:
    int binarySearch(vector<int>& nums, int first, int last, int target, bool findFirst) {
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                if (findFirst) {
                    if (mid == 0 || nums[mid - 1] != target) {
                        return mid;
                    } else {
                        last = mid - 1;
                    }
                } else {
                    if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                        return mid;
                    } else {
                        first = mid + 1;
                    }
                }
            } else if (nums[mid] > target) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, 0, nums.size() - 1, target, true);
        int last = binarySearch(nums, 0, nums.size() - 1, target, false);
        return {first, last};
    }
};
