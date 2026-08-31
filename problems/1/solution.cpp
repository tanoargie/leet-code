class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;
    unordered_map<int, int> pastSeenPositions;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      unordered_map<int, int>::iterator it = pastSeenPositions.find(diff);
      if (it != pastSeenPositions.end()) {
        res.push_back(i);
        res.push_back(it->second);
        return res;
      } else {
        pastSeenPositions[nums[i]] = i;
      }
    }

    return res;
  }
};
