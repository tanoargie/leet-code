class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {
    int res = 0;
    int left = 0;
    int total = colors.size();
    int right = left;
    while (left < colors.size() && right < total + k - 1) {
      if (colors[right % total] != colors[(right + 1) % total]) {
        right++;
      } else {
        left = right + 1;
        right = left;
      }
      if (right - left + 1 == k) {
        res++;
        left++;
      }
    }
    return res;
  }
};
