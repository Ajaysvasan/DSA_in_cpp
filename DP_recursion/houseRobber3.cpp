#include <iostream>
#include <queue>
#include <vector>

struct Node {
  int data;
  Node *right;
  Node *left;
  Node(int data) {
    this->data = data;
    right = nullptr;
    left = nullptr;
  }
};

class BinaryTree {
  Node *root;
  Node *insertIntoTree(int data, Node *root) {
    if (root == nullptr) {
      root = new Node(data);
      return root;
    }
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *curr_node = q.front();
      q.pop();
      q.push(curr_node);
      if (curr_node->left != nullptr) {
        q.push(curr_node->left);
      } else {
        curr_node->left = new Node(data);
        return root;
      }
      if (curr_node->right != nullptr) {
        q.push(curr_node->right);
      } else {
        curr_node->right = new Node(data);
        return root;
      }
    }
  }

public:
  BinaryTree() { root = nullptr; }
  void insert(int data) { root = insertIntoTree(data, root); }
};
