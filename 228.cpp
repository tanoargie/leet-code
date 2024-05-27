class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> res;
    if (nums.size() == 0) {
      return res;
    }
    int start = 0;
    int end = 0;
    int intervalNum = 1;
    string interval;
    while (end < nums.size()) {
      if (start == end) {
        interval += std::to_string(nums[start]);
        end++;
      } else {
        if (nums[start] + intervalNum == nums[end]) {
          intervalNum++;
          end++;
        } else {
          if (intervalNum > 1) {
            interval += ("->" + std::to_string(nums[end - 1]));
          }
          res.push_back(interval);
          interval = "";
          start = end;
          intervalNum = 1;
        }
      }
    }
    if (interval.size() > 0) {
      if (intervalNum > 1) {
        interval += ("->" + std::to_string(nums[end - 1]));
      }
      res.push_back(interval);
    }

    return res;
  }
};
