class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> left(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); i++) {
      res *= nums[i - 1];
      left[i] = res;
    }
    res = 1;
    int lastOne = nums[nums.size() - 1];
    nums[nums.size() - 1] = 1;
    // nums to be right
    for (int i = nums.size() - 2; i >= 0; i--) {
      res *= lastOne;
      lastOne = nums[i];
      nums[i] = res;
    }
    for (int i = 0; i < nums.size(); i++) {
      left[i] = left[i] * nums[i];
    }

    return left;
  }
};
