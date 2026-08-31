class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> groups;
    vector<vector<string>> res;
    for (int i = 0; i < strs.size(); i++) {
      string copy = strs[i];
      sort(strs[i].begin(), strs[i].end());
      groups[strs[i]].push_back(copy);
    }

    unordered_map<string, vector<string>>::iterator it = groups.begin();
    while (it != groups.end()) {
      res.push_back(it->second);
      it++;
    }
    return res;
  }
};
