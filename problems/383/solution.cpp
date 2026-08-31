class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    bool result = true;
    unordered_map<char, int> occurrencesMag;
    for (int i = 0; i < magazine.size(); i++) {
      occurrencesMag[magazine[i]]++;
    }
    unordered_map<char, int> occurrencesRan;
    for (int i = 0; i < ransomNote.size(); i++) {
      occurrencesRan[ransomNote[i]]++;
      if (occurrencesRan[ransomNote[i]] > occurrencesMag[ransomNote[i]]) {
        result = false;
        break;
      }
    }

    return result;
  }
};
