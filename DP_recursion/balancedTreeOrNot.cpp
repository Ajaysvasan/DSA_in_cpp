#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
  int dfs(TreeNode *node, int &diameter) {
    if (!node)
      return 0;
    int left = dfs(node->left, diameter);
    int right = dfs(node->right, diameter);
    if (abs(left - right) > 1)
      return -1;
    return 1 + max(left, right);
  }

public:
  bool diameterOfBinaryTree(TreeNode *root) {}
};
