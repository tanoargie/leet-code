class Solution {
public:
  bool isSubsequence(string s, string t) {
    int sIt = 0;
    int tIt = 0;
    while (sIt < s.size() && tIt < t.size()) {
      if (s[sIt] == t[tIt]) {
        sIt++;
      }
      tIt++;
    }
    if (sIt == s.size()) {
      return true;
    }
    return false;
  }
};
