class Solution {
public:
  int earliestTime(vector<vector<int>> &tasks) {
    int min = tasks[0][1] + tasks[0][0];
    for (int i = 0; i < tasks.size(); i++) {
      if (tasks[i][0] + tasks[i][1] < min) {
        min = tasks[i][0] + tasks[i][1];
      }
    }
    return min;
  }
};
