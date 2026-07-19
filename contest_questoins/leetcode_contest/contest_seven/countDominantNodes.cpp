#include <algorithm>
#include <bits/stdc++.h>
#include <pthread.h>
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
struct Info {
  int dominantCount;
  long long maxVal;
};

class Solution {
  Info dfs(TreeNode *node) {
    if (!node) {
      return {0, LLONG_MIN};
    }

    Info left = dfs(node->left);
    Info right = dfs(node->right);

    int currentCount = left.dominantCount + right.dominantCount;

    if (node->val >= left.maxVal && node->val >= right.maxVal) {
      currentCount++;
    }

    long long currentMax =
        std::max({(long long)node->val, left.maxVal, right.maxVal});

    return {currentCount, currentMax};
  }

public:
  int countDominantNodes(TreeNode *root) { return dfs(root).dominantCount; }
};
