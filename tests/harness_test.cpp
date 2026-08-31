#include "gtest/gtest.h"
#include "harness/leet.h"

TEST(BuildTree, Empty) {
  EXPECT_EQ(buildTree({}), nullptr);
}

TEST(BuildTree, SingleNull) {
  EXPECT_EQ(buildTree({std::nullopt}), nullptr);
}

TEST(BuildTree, Example) {
  TreeNode* root = buildTree({1, std::nullopt, 2, 3});
  ASSERT_NE(root, nullptr);
  EXPECT_EQ(root->val, 1);
  EXPECT_EQ(root->left, nullptr);
  ASSERT_NE(root->right, nullptr);
  EXPECT_EQ(root->right->val, 2);
  ASSERT_NE(root->right->left, nullptr);
  EXPECT_EQ(root->right->left->val, 3);
}

TEST(ToVectorTree, Example) {
  TreeNode* root = buildTree({1, std::nullopt, 2, 3});
  EXPECT_EQ(toVector(root), (std::vector<std::optional<int>>{1, std::nullopt, 2, 3}));
}

TEST(BuildList, Empty) {
  EXPECT_EQ(buildList({}), nullptr);
}

TEST(BuildList, Example) {
  ListNode* head = buildList({1, 2, 3});
  ASSERT_NE(head, nullptr);
  EXPECT_EQ(head->val, 1);
  ASSERT_NE(head->next, nullptr);
  EXPECT_EQ(head->next->val, 2);
  ASSERT_NE(head->next->next, nullptr);
  EXPECT_EQ(head->next->next->val, 3);
  EXPECT_EQ(head->next->next->next, nullptr);
}

TEST(ToVectorList, Example) {
  ListNode* head = buildList({1, 2, 3});
  EXPECT_EQ(toVector(head), (std::vector<int>{1, 2, 3}));
}

TEST(NodeVariants, BothExist) {
  GraphNode g(1);
  g.neighbors.push_back(new GraphNode(2));
  EXPECT_EQ(g.neighbors[0]->val, 2);
  RandomListNode r(7);
  EXPECT_EQ(r.next, nullptr);
  EXPECT_EQ(r.random, nullptr);
}
