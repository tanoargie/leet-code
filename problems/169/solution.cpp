class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int count = 1;
    int candidate = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == candidate) {
        count++;
      } else {
        count--;
        if (count == 0) {
          candidate = nums[i];
          count++;
        }
      }
    }
    // assumes the candidate always exist,
    // so no need to go through array again to verify it
    // meaning always count > [n/2]
    return candidate;
  }
};
