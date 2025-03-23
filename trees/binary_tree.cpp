#include <iostream>
#include <vector>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int val) {
        data = val;
        leftChild = rightChild = nullptr;
    }
};

// Binary Tree (BST) class
class BinaryTree {
private:
    Node* root;

    // Helper: Insert node recursively
    Node* insertNode(Node* node, int data) {
        if (node == nullptr)
            return new Node(data);

        if (data < node->data)
            node->leftChild = insertNode(node->leftChild, data);
        else
            node->rightChild = insertNode(node->rightChild, data);

        return node;
    }

    // Helper: In-order traversal recursively
    void inOrderTraversal(Node* node, vector<int>& result) {
        if (node) {
            inOrderTraversal(node->leftChild, result);
            result.push_back(node->data);
            inOrderTraversal(node->rightChild, result);
        }
    }

    // Helper: Search recursively
    bool searchElement(Node* node, int target) {
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
    BinaryTree() {
        root = nullptr;
    }

    // Public Insert
    void insert(int data) {
        root = insertNode(root, data);
    }

    // Public In-order Traversal
    vector<int> inOrderTraversal() {
        vector<int> result;
        inOrderTraversal(root, result);
        return result;
    }

    // Public Search
    void search(int target) {
        searchElement(root, target);
    }
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
    tree.search(11);  // Try changing this value

    return 0;
}
