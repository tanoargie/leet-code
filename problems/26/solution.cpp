class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    vector<int>::iterator behind = nums.begin();
    vector<int>::iterator it = nums.begin() + 1;
    int count = 1;
    while (it != nums.end()) {
      if (*behind == *it) {
        ++it;
      } else {
        behind = nums.erase(behind + 1, it);
        it = behind + 1;
        count++;
      }
    }

    return count;
  }
};
