#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int max = 0;
    int start = 0;
    int n = s.size();

    for (int mid = 0; mid < n; mid++) {
      for (int margins = 0; mid - margins >= 0 && mid + margins < n;
           margins++) {
        if (s[mid + margins] != s[mid - margins]) {
          break;
        }
        int len = (margins * 2) + 1;
        if (len > max) {
          max = len;
          start = mid - margins;
        }
      }
    }

    for (int mid = 0; mid < n - 1; mid++) {
      if (s[mid] == s[mid + 1]) {
        if (2 > max) {
          max = 2;
          start = mid;
        }
        for (int margins = 1; mid - margins >= 0 && mid + margins < n - 1;
             margins++) {
          if (s[mid - margins] != s[mid + margins + 1]) {
            break;
          }
          int len = (margins * 2) + 2;
          if (s[mid - margins] == s[mid + margins + 1] && len > max) {
            max = len;
            start = mid - margins;
          }
        }
      }
    }

    return s.substr(start, max);
  }
};
