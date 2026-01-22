#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

// Binary Tree (BST) class
class BinaryTree {
private:
  struct Node {
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int val) {
      data = val;
      leftChild = rightChild = nullptr;
    }
  };

public:
  int maxHeight = 0;
  Node *root;

private:
  // Helper: Insert node recursively
  Node *insertNode(Node *node, int data) {
    if (node == nullptr)
      return new Node(data);

    if (data < node->data)
      node->leftChild = insertNode(node->leftChild, data);
    else
      node->rightChild = insertNode(node->rightChild, data);

    return node;
  }

  // Helper: In-order traversal recursively
  // DFS
  void inOrderTraversal(Node *node, vector<int> &result) {
    if (node) {
      inOrderTraversal(node->leftChild, result);
      result.push_back(node->data);
      inOrderTraversal(node->rightChild, result);
    }
  }

public:
  void BFS(Node *node, int level, vector<vector<int>> &res) {
    if (!node) {
      return;
    }
    if (res.size() <= level) {
      res.push_back(vector<int>());
    }
    res[level].push_back(node->data);
    BFS(node->leftChild, level + 1, res);
    BFS(node->rightChild, level + 1, res);
  }
  vector<vector<int>> levelOrder(Node *node) {
    vector<vector<int>> res;
    BFS(node, 0, res);
    return res;
  }

  void zigzag(Node *node) {
    if (!node)
      return;
    deque<Node *> dq;
    dq.push_front(node);
    bool leftToRight = true;
    while (!dq.empty()) {
      int size = dq.size();
      for (int i = 0; i < size; i++) {
        if (leftToRight) {
          Node *temp = dq.front();
          dq.pop_front();
          cout << temp->data << " ";
          if (temp->leftChild)
            dq.push_back(temp->leftChild);
          if (temp->rightChild)
            dq.push_back(temp->rightChild);
        } else {
          Node *temp = dq.back();
          dq.pop_back();
          cout << temp->data << " ";
          if (temp->rightChild)
            dq.push_front(temp->rightChild);
          if (temp->leftChild)
            dq.push_front(temp->leftChild);
        }
      }

      leftToRight = !leftToRight;
    }
  }

  void height(Node *node, int level) {
    if (node == nullptr)
      return;
    if (level > maxHeight) {
      maxHeight = level;
    }
    height(node->leftChild, level + 1);
    height(node->rightChild, level + 1);
  }

  // to check if the tree is balanced or not
  int calHeight(Node *root) {
    if (root == nullptr)
      return 0;
    int lh = calHeight(root->leftChild);
    if (lh == -1)
      return -1;
    int rh = calHeight(root->rightChild);
    if (rh == -1)
      return -1;
    if (abs(lh - rh) > 1)
      return -1;
    return 1 + max(lh, rh);
  }
  bool isTreeBalanced(Node *root) { return calHeight(root); }

  int res = 0;
  int dfs(Node *root) {
    if (!root)
      return 0;
    int lh = dfs(root->leftChild);
    int rh = dfs(root->rightChild);
    res = max(res, lh + rh);
    return 1 + max(lh, rh);
  }
  int diameterOfTree(Node *root) {
    dfs(root);
    return res;
  }

private:
  // Helper: Search recursively
  bool searchElement(Node *node, int target) {
    if (node == nullptr) {
      cout << "The element is not Found" << endl;
      return false;
    }
    if (node->data == target) {
      cout << "The element is Found" << endl;
      return true;
    }
    if (target < node->data)
      return searchElement(node->leftChild, target);
    else
      return searchElement(node->rightChild, target);
  }

public:
  // Constructor
  BinaryTree() { root = nullptr; }

  // Public Insert
  void insert(int data) { root = insertNode(root, data); }

  // Public In-order Traversal
  vector<int> inOrderTraversal() {
    vector<int> result;
    inOrderTraversal(root, result);
    return result;
  }

  // Public Search
  void search(int target) { searchElement(root, target); }
};

// Main function
int main() {
  BinaryTree tree;

  int values[] = {7, 4, 9, 1, 6, 8, 10};
  for (int val : values) {
    tree.insert(val);
  }

  // In-order traversal
  vector<int> inorder = tree.inOrderTraversal();
  cout << "Inorder Traversal: ";
  for (int val : inorder)
    cout << val << " ";
  cout << endl;

  // Search test
  tree.search(11); // Try changing this value
  vector<vector<int>> res = tree.levelOrder(tree.root);
  for (vector<int> nums : res) {
    for (int num : nums) {
      cout << num << " ";
    }
  }
  cout << "\nZigZag: ";
  // tree.zigzag(tree.root);
  tree.height(tree.root, 0);
  cout << "\nThe height of the tree is: " << tree.maxHeight;
  return 0;
}
