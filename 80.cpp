class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int countinuousAppearances = 0;
    int count = 0;
    vector<int>::iterator it = nums.begin();
    int lastValue = *it;
    while (it != nums.end()) {
      if (*it != lastValue) {
        lastValue = *it;
        countinuousAppearances = 0;
      } else {
        if (countinuousAppearances < 2) {
          ++it;
          countinuousAppearances++;
          count++;
        } else {
          it = nums.erase(it);
        }
      }
    }

    return count;
  }
};
