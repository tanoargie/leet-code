class Solution {
public:
  vector<vector<int>> findSum(int target, vector<int> &nums, int filterPos) {
    int start = filterPos + 1;
    int end = nums.size() - 1;
    vector<vector<int>> res;
    // cout << nums[filterPos] << endl;
    while (start < end) {
      if (start > filterPos + 1 && end < nums.size() - 1 &&
          nums[start] == nums[start - 1] && nums[end] == nums[end + 1]) {
        start++;
        end--;
        continue;
      }
      if (nums[start] + nums[end] == target) {
        int myints[] = {nums[filterPos], nums[start], nums[end]};
        vector<int> solution(myints, myints + sizeof(myints) / sizeof(int));
        // cout << start << " " << end << endl;
        res.push_back(solution);
        start++;
        end--;
      } else if (nums[start] + nums[end] < target) {
        start++;
      } else {
        end--;
      }
    }
    return res;
  }
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    int i = 0;
    while (i < nums.size()) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        i++;
        continue;
      }
      // cout << i << endl;
      int fixed = nums[i];
      int sumToFind = 0 - fixed;
      vector<vector<int>> possibles = findSum(sumToFind, nums, i);
      for (int j = 0; j < possibles.size(); j++) {
        res.push_back(possibles[j]);
      }
      i++;
    }
    return res;
  }
};
