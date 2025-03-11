class Solution {
public:
  int numberOfSubstrings(string s) {
    int res = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      if (s[right] == 'a') {
        a++;
      } else if (s[right] == 'b') {
        b++;
      } else if (s[right] == 'c') {
        c++;
      }
      while (a > 0 && b > 0 && c > 0) {
        res += s.size() - right;
        if (s[left] == 'a') {
          a--;
        } else if (s[left] == 'b') {
          b--;
        } else if (s[left] == 'c') {
          c--;
        }
        left++;
      }
    }
    return res;
  }
};
