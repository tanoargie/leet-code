class Solution {
public:
  vector<int> getSpaces(string &word, int maxWidth) {
    int spaces = 0;
    for (int i = 0; i < word.size(); i++) {
      if (word[i] == '*') {
        spaces++;
      }
    }
    vector<int> res(spaces, 0);
    int characters = word.size() - spaces;
    int widthMinusChars = maxWidth - characters;
    // have to divide widthMinusChars between spaces evenly
    if (spaces > 0) {
      for (int i = 0; i < widthMinusChars; i++) {
        res[i % spaces] += 1;
      }
    }
    return res;
  }
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> res;
    string currentLine = words[0];
    for (int i = 1; i < words.size(); i++) {
      if (words[i].size() + currentLine.size() + 1 <= maxWidth) {
        currentLine += '*';
        currentLine += words[i];
      } else {
        res.push_back(currentLine);
        currentLine = words[i];
      }
    }
    res.push_back(currentLine);
    for (int i = 0; i < res.size(); i++) {
      string word = res[i];
      if (i == res.size() - 1) {
        int j = 0;
        while (j < word.size()) {
          if (word[j] == '*') {
            word[j] = ' ';
          }
          j++;
        }
        while (j < maxWidth) {
          word.append(" ");
          j++;
        }
      } else {
        vector<int> spaces = getSpaces(word, maxWidth);
        int spaceIt = 0;
        int j = 0;
        while (j < word.size()) {
          if (word[j] == '*') {
            word[j] = ' ';
            word.insert(j, spaces[spaceIt] - 1, ' ');
            j = j + spaces[spaceIt];
            spaceIt++;
          } else {
            j++;
          }
        }
        while (j < maxWidth) {
          word.append(" ");
          j++;
        }
      }
      res[i] = word;
    }

    return res;
  }
};
