class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> isMappedToS;
    unordered_set<char> alreadyMappedT;
    bool result = true;

    for (int i = 0; i < t.size(); i++) {
      unordered_map<char, char>::iterator it = isMappedToS.find(s[i]);
      if (it != isMappedToS.end() && it->second != t[i]) {
        result = false;
        break;
      } else if (it == isMappedToS.end()) {
        unordered_set<char>::iterator it1 = alreadyMappedT.find(t[i]);
        if (it1 != alreadyMappedT.end()) {
          // it was already mapped to another one
          result = false;
          break;
        } else {
          // add to map
          isMappedToS[s[i]] = t[i];
          alreadyMappedT.insert(t[i]);
        }
      }
    }

    return result;
  }
};
