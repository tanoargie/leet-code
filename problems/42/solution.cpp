class Solution {
public:
  int trap(vector<int> &height) {
    int water = 0;
    vector<int> left(height.size(), 0);
    vector<int> right(height.size(), 0);
    int max = height[0];
    left[0] = max;
    for (int i = 1; i < height.size(); i++) {
      max = std::max(max, height[i]);
      left[i] = max;
    }
    max = height[height.size() - 1];
    right[height.size() - 1] = max;
    for (int i = height.size() - 2; i >= 0; i--) {
      max = std::max(max, height[i]);
      right[i] = max;
    }
    for (int i = 0; i < height.size(); i++) {
      water += std::min(left[i], right[i]) - height[i];
    }

    return water;
  }
};
