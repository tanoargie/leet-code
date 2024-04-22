class Solution {
public:
  int jump(vector<int> &nums) {
    vector<int> minJumpsFrom(nums.size(), 0);
    for (int i = nums.size() - 2; i >= 0; i--) {
      int minsToTop = nums.size();
      for (int j = 1; i + j < nums.size() && j <= nums[i]; j++) {
        if (minJumpsFrom[i + j] < minsToTop) {
          minsToTop = minJumpsFrom[i + j];
        }
      }
      minJumpsFrom[i] = 1 + minsToTop;
    }

    return minJumpsFrom[0];
  }
};
