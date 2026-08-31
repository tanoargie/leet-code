class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    vector<int>::iterator it = nums.begin();
    int count = 0;
    while (it != nums.end()) {
      if (*it == val) {
        it = nums.erase(it);
      } else {
        count++;
        ++it;
      }
    }
    return count;
  }
};
