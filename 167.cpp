class Solution {
public:
  int findRightPosition(int from, vector<int> &numbers, int target) {
    // do binary search between from position + 1 until end
    int left = from;
    int right = numbers.size() - 1;
    while (left <= right) {
      int middle = floor((left + right) / 2);
      if (numbers[middle] == target) {
        return middle;
      } else if (numbers[middle] < target) {
        left = middle + 1;
      } else if (numbers[middle] > target) {
        right = middle - 1;
      }
    }
    return -1;
  }
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    int left = 0;
    while (left < numbers.size()) {
      int newTarget = target - numbers[left];
      int found = findRightPosition(left + 1, numbers, newTarget);
      if (found < 0) {
        left++;
      } else {
        res.push_back(left + 1);
        res.push_back(found + 1);
        return res;
      }
    }
    return res;
  }
};
