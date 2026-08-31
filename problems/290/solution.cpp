class Solution {
public:
  bool wordPattern(string pattern, string s) {
    bool result = true;
    unordered_map<char, string> mappedToS;
    unordered_map<string, char> mappedToP;
    int j = 0;
    for (int i = 0; i < pattern.size(); i++) {
      string word;
      while (j < s.size() && s[j] != ' ') {
        word += s[j];
        j++;
      }
      if (j == s.size() && i < pattern.size() - 1) {
        result = false;
        break;
      }
      j++;
      unordered_map<char, string>::iterator it = mappedToS.find(pattern[i]);
      unordered_map<string, char>::iterator it2 = mappedToP.find(word);
      if (it == mappedToS.end()) {
        mappedToS[pattern[i]] = word;
        if (it2 == mappedToP.end()) {
          mappedToP[word] = pattern[i];
        } else {
          result = false;
          break;
        }
      } else {
        if (word != it->second) {
          result = false;
          break;
        }
        if (it2 != mappedToP.end() && it2->second != pattern[i]) {
          result = false;
          break;
        }
      }
    }

    if (j < s.size()) {
      return false;
    }

    return result;
  }
};
