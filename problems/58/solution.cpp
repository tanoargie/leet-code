class Solution {
public:
  int lengthOfLastWord(string s) {
    int lastPos = s.size() - 1;
    while (s[lastPos] == ' ') {
      lastPos--;
    }
    int count = 0;
    while (lastPos >= 0 && s[lastPos] != ' ') {
      count++;
      lastPos--;
    }

    return count;
  }
};
