class Solution {
public:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  long long atLeastK(string &word, int k) {
    long long res = 0;
    int left = 0;
    int consonants = 0;
    unordered_map<char, int> vowels;
    for (int right = 0; right < word.size(); right++) {
      if (isVowel(word[right])) {
        vowels[word[right]]++;
      } else {
        consonants++;
      }
      while (vowels.size() == 5 && consonants >= k) {
        res += word.size() - right;
        if (isVowel(word[left])) {
          vowels[word[left]]--;
          if (vowels[word[left]] == 0) {
            vowels.erase(word[left]);
          }
        } else {
          consonants--;
        }
        left++;
      }
    }

    return res;
  }
  long long countOfSubstrings(string word, int k) {
    return atLeastK(word, k) - atLeastK(word, k + 1);
  }
};
