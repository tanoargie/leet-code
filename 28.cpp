class Solution {
public:
  int strStr(string haystack, string needle) {
    int res = 0;
    int start = 0;
    int i = 0;
    while (i < haystack.size()) {
      if (haystack[i] == needle[start]) {
        res = i;
        while (i < haystack.size() && haystack[i] == needle[start]) {
          i++;
          start++;
        }
        if (start == needle.size()) {
          return res;
        } else {
          start = 0;
          i = res + 1;
        }
      } else {
        i++;
      }
    }

    return -1;
  }
};
