class Solution {
public:
  string reverseWords(string s) {
    vector<string> res;
    int i = 0;
    while (i < s.size()) {
      while (s[i] == ' ') {
        i++;
      }
      string word;
      while (i < s.size() && s[i] != ' ') {
        word += s[i];
        i++;
      }
      if (word.size() > 0) {
        res.push_back(word);
      }
    }
    reverse(res.begin(), res.end());
    string result;
    for (int i = 0; i < res.size(); i++) {
      result += res[i];
      if (i != res.size() - 1) {
        result += ' ';
      }
    }

    return result;
  }
};
