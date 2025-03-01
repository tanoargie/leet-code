class Solution {
public:
  vector<int> applyOperations(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        nums[i - 1] *= 2;
        nums[i] = 0;
      }
    }
    int j = 0;
    int i = 0;
    vector<int> result;
    while (i < nums.size()) {
      if (nums[i] != 0) {
        j++;
        result.push_back(nums[i]);
      }
      i++;
    }
    while (j < nums.size()) {
      result.push_back(0);
      j++;
    }
    return result;
  }
};
