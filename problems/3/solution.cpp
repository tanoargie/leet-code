class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max = 0;
    int start = 0;
    map<char, int> occurrences;
    for (int i = 0; i < s.size(); i++) {
      map<char, int>::iterator it = occurrences.find(s[i]);
      if (it != occurrences.end() && start <= it->second) {
        start = it->second + 1;
      }
      max = std::max(i - start + 1, max);

      occurrences[s[i]] = i;
    }
    return max;
  }
};
