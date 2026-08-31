class Solution {
public:
  vector<int> transformArray(vector<int> &nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      int res = nums[i] % 2 == 0 ? 0 : 1;
      if (res == 0) {
        result.insert(result.begin(), res);
      } else {
        result.insert(result.end(), res);
      }
    }
    return result;
  }
};
