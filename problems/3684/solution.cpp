class Solution {
public:
  struct classcomp {
    bool operator()(const int &lhs, const int &rhs) const { return lhs > rhs; }
  };
  vector<int> maxKDistinct(vector<int> &nums, int k) {
    vector<int> res;
    set<int, classcomp> orderedOccurences;
    for (int i = 0; i < nums.size(); i++) {
      orderedOccurences.insert(nums[i]);
    }
    auto it = orderedOccurences.begin();
    while (it != orderedOccurences.end() && k > 0) {
      k -= 1;
      res.push_back(*it);
      it++;
    }
    return res;
  }
};
