class Solution {
public:
  bool canJump(vector<int> &nums) {
    bool canJump = true;
    int zeroes = 0;
    if (nums.size() == 1)
      return true;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[nums.size() - i - 1] >= 1 + zeroes) {
        canJump = true;
        zeroes = 0;
      } else {
        zeroes++;
        canJump = false;
      }
    }

    return canJump;
  }
};
