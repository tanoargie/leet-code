class Solution {
public:
  bool isPalindrome(string s) {
    bool res = true;
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      while (left < s.size() && isalnum(s[left]) == 0) {
        left++;
      }
      while (right >= 0 && isalnum(s[right]) == 0) {
        right--;
      }
      if (left < right && tolower(s[left]) != tolower(s[right])) {
        return false;
      }
      left++;
      right--;
    }
    return res;
  }
};
