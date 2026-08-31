class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int shift = nums.size() - (k % nums.size());
    std::rotate(nums.begin(), nums.begin() + shift, nums.end());
  }
};
