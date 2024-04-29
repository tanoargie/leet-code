class Solution {
public:
  static bool compare(string s1, string s2) { return s1.size() < s2.size(); }
  string longestCommonPrefix(vector<string> &strs) {
    string res = "";
    string firstString = strs[0];
    int lastCommon = 0;
    while (lastCommon < firstString.size()) {
      int i = 0;
      while (i < strs.size() && lastCommon < strs[i].size() &&
             firstString[lastCommon] == strs[i][lastCommon]) {
        i++;
      }
      if (i == strs.size()) {
        res += firstString[lastCommon];
        lastCommon++;
      } else {
        break;
      }
    }

    return res;
  }
};
