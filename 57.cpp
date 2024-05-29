class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    if (intervals.size() == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    int start = 0;
    int end = intervals.size() - 1;
    while (start <= end) {
      int middle = floor((end + start) / 2);
      if (intervals[middle][0] <= newInterval[1]) {
        start = middle + 1;
      } else {
        end = middle - 1;
      }
    }
    // we should insert newInterval in start position
    // while newInterval[0] <= previous[1], merge with previous
    intervals.insert(intervals.begin() + start, newInterval);
    end = start;
    while (start > 0 && intervals[start - 1][1] >= intervals[start][0]) {
      intervals[start - 1] = {
          min(intervals[start][0], intervals[start - 1][0]),
          max(intervals[start][1], intervals[start - 1][1])};
      start--;
    }
    if (start <= end) {
      intervals.erase(intervals.begin() + start + 1,
                      intervals.begin() + end + 1);
    }

    return intervals;
  }
};
