class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> pastPositions;
    bool res = false;
    for (int i = 0; i < nums.size(); i++) {
      unordered_map<int, int>::iterator it = pastPositions.find(nums[i]);
      if (it != pastPositions.end()) {
        if (abs(it->second - i) <= k) {
          return true;
        }
      }
      pastPositions[nums[i]] = i;
    }
    return res;
  }
};
