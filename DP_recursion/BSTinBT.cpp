#include <algorithm>
#include <climits>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
struct Info {
  bool isBST;
  int minVal;
  int maxVal;
  int size;
};

class Solution {
private:
  Info dfs(TreeNode *node) {

    if (node == nullptr) {
      return {true, INT_MAX, INT_MIN, 0};
    }

    Info left = dfs(node->left);
    Info right = dfs(node->right);

    if (left.isBST && right.isBST && left.maxVal < node->val &&
        node->val < right.minVal) {
      return {true, std::min(left.minVal, node->val),
              std::max(right.maxVal, node->val), left.size + right.size + 1};
    }

    return {false, INT_MIN, INT_MAX, std::max(left.size, right.size)};
  }

public:
  int largestBSTSubtree(TreeNode *root) { return dfs(root).size; }
};
