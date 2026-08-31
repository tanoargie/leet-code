class Solution {
public:
  static bool comp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }
  int findMinArrowShots(vector<vector<int>> &points) {
    int min = points.size();
    sort(points.begin(), points.end(), comp);
    int i = 0;
    while (i < points.size()) {
      int j = i + 1;
      while (j < points.size() && points[i][1] >= points[j][0]) {
        j++;
      }
      min -= (j - i - 1);
      if (min == 1) {
        return min;
      }
      i = j;
    }

    return min;
  }
};
