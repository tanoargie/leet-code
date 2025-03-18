class Solution {
public:
  bool divideArray(vector<int> &nums) {
    vector<int> appearances(501, 0);
    for (int i = 0; i < nums.size(); i++) {
      appearances[nums[i]]++;
    }
    bool res = true;
    for (int i = 0; i < appearances.size() && res; i++) {
      if (appearances[i] % 2 != 0) {
        res = false;
      }
    }
    return res;
  }
};
