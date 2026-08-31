class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    int max = 0;
    unordered_set<int> seen;
    for (int i = 0; i < nums.size(); i++) {
      seen.insert(nums[i]);
    }
    for (unordered_set<int>::iterator it = seen.begin(); it != seen.end();
         it++) {
      unordered_set<int>::iterator otherIt = seen.find(*it - 1);
      if (otherIt == seen.end()) {
        int count = 0;
        int number = *it;
        otherIt = seen.find(number);
        while (otherIt != seen.end()) {
          count++;
          otherIt = seen.find(++number);
        }
        if (count > max) {
          max = count;
        }
      }
    }
    return max;
  }
};
