class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res{intervals[0]};

    int i = 0;
    for (int j = 1; j < intervals.size(); j++) {
      if (intervals[j][0] <= res[i][1]) {
        res[i] = {res[i][0], max(intervals[j][1], res[i][1])};
      } else {
        i++;
        res.push_back(intervals[j]);
      }
    }

    return res;
  }
};
