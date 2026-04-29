class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pivot = nums[nums.size() / 2];

        vector<int> left, mid, right;

        for (int num : nums) {
            if (num > pivot) {
                right.push_back(num);
            }
            else if (num < pivot) {
                left.push_back(num);
            }
            else {
                mid.push_back(num);
            }
        }
        if (k <= right.size()) {
            return findKthLargest(right, k);
        }
        if (k <= right.size() + mid.size()) {
            return pivot;
        }
        return findKthLargest(left, k - right.size() - mid.size());
    }
};