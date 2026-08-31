class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int start = 0;
    int currSum = 0;
    int res = nums.size() + 1;
    for (int i = 0; i < nums.size(); i++) {
      currSum += nums[i];

      while (currSum >= target) {
        res = min(res, i + 1 - start);
        currSum -= nums[start];
        start++;
      }
    }
    if (res > nums.size()) {
      return 0;
    }

    return res;
  }
};
