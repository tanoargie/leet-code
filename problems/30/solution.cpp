class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> result;
    map<string, int> words2;
    map<string, int> words3;
    for (int i = 0; i < words.size(); i++) {
      words2[words[i]]++;
    }
    int size = words.size() * words[0].size();
    if (s.size() < size) {
      return result;
    }
    for (int i = 0; i <= s.size() - size; i++) {
      string substring = s.substr(i, size);
      for (int j = 0; j < substring.size(); j += words[0].size()) {
        string sub2 = substring.substr(j, words[0].size());
        map<string, int>::iterator it = words2.find(sub2);
        if (it != words2.end()) {
          words3[sub2]++;
        } else {
          break;
        }
      }
      bool isSame = true;
      for (map<string, int>::iterator it = words2.begin();
           isSame && it != words2.end(); it++) {
        if (it->second != words3[it->first]) {
          isSame = false;
        }
      }
      words3.clear();
      if (isSame) {
        result.push_back(i);
      }
    }
    return result;
  }
};
