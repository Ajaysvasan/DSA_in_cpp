#include <algorithm>
#include <utility>

struct TreeNode {
  int data;
  TreeNode *right;
  TreeNode *left;
  TreeNode(int data) {
    this->data = data;
    right = nullptr;
    left = nullptr;
  }
} *root;

class Solution {
  std::pair<int, int> dfs(TreeNode *node) {
    if (node == nullptr) {
      return {0, 0};
    }
    auto left = dfs(node->left);
    auto right = dfs(node->right);
    int take = node->data + left.second + right.second;
    int skip =
        std::max(left.first, left.second) + std::max(right.first, right.second);
    return {take, skip};
  }

public:
  int rob(TreeNode *root) {
    std::pair<int, int> result = dfs(root);
    return std::max(result.first, result.second);
  }
};
