class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                  vector<vector<int>> &nums2) {
    int pointer1 = 0;
    int pointer2 = 0;
    vector<vector<int>> result;
    while (pointer1 < nums1.size() && pointer2 < nums2.size()) {
      vector<int> curr1 = nums1[pointer1];
      vector<int> curr2 = nums2[pointer2];

      vector<int> resultCurr;
      if (curr1[0] == curr2[0]) {
        resultCurr.push_back(curr1[0]);
        resultCurr.push_back(curr1[1] + curr2[1]);
        pointer1++;
        pointer2++;
      } else if (curr1[0] < curr2[0]) {
        resultCurr.push_back(curr1[0]);
        resultCurr.push_back(curr1[1]);
        pointer1++;
      } else {
        resultCurr.push_back(curr2[0]);
        resultCurr.push_back(curr2[1]);
        pointer2++;
      }
      result.push_back(resultCurr);
    }
    while (pointer1 < nums1.size()) {
      result.push_back(nums1[pointer1]);
      pointer1++;
    }
    while (pointer2 < nums2.size()) {
      result.push_back(nums2[pointer2]);
      pointer2++;
    }
    return result;
  }
};
