class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    int res = -1;
    while (low + 1 < high && res < 0) {
      int middle = (low + high) / 2;
      if (nums[middle] == target) {
        res = middle;
      } else if (nums[middle] < target) {
        low = middle;
      } else if (nums[middle] > target) {
        high = middle;
      }
    }
    if (res < 0) {
      if (target > nums[high])
        return high + 1;
      if (target > nums[low])
        return low + 1;
      return low;
    }
    return res;
  }
};
