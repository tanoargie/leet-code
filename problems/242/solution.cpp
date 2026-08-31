class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> occurrences;
    if (s.size() != t.size()) {
      return false;
    }
    for (int i = 0; i < s.size(); i++) {
      occurrences[s[i]]++;
    }
    int count = 0;
    for (int i = 0; i < t.size(); i++) {
      occurrences[t[i]]--;
      if (occurrences[t[i]] == 0) {
        count++;
      }
    }
    if (count == occurrences.size()) {
      return true;
    }
    return false;
  }
};
