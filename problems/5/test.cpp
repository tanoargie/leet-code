#include "solution.cpp"
#include <gtest/gtest.h>

TEST(LongestPalindrome, Odd) {
  Solution s;
  EXPECT_EQ(s.longestPalindrome("babad"), "bab");
  EXPECT_EQ(s.longestPalindrome("abb"), "bb");
  EXPECT_EQ(s.longestPalindrome("abcde"), "a");
  EXPECT_EQ(s.longestPalindrome("abaaaba"), "abaaaba");
  EXPECT_EQ(s.longestPalindrome("bbbbb"), "bbbbb");
}

TEST(LongestPalindrome, Even) {
  Solution s;
  EXPECT_EQ(s.longestPalindrome("aaaa"), "aaaa");
  EXPECT_EQ(s.longestPalindrome("abba"), "abba");
  EXPECT_EQ(s.longestPalindrome("abccba"), "abccba");
  EXPECT_EQ(s.longestPalindrome("abccbd"), "bccb");
  EXPECT_EQ(s.longestPalindrome("cbbd"), "bb");
}
