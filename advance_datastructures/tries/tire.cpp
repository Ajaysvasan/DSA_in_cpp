#include <string>
#include <vector>
class TrieNode {
public:
  std::vector<TrieNode *> children;
  bool isEndOfWord;
  TrieNode() {
    children.resize(26);
    isEndOfWord = false;
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(std::string word) {
    TrieNode *current = root;
    for (int i = 0; i < word.size(); i++) {
      int nodeIdx = word[i] - 'a';
      if (!current->children[nodeIdx]) {
        current->children[nodeIdx] = new TrieNode();
      }
      current = current->children[nodeIdx];
    }

    current->isEndOfWord = true;
  }

  bool search(std::string word) {

    TrieNode *current = root;
    for (char letter : word) {
      if (!current->children[letter - 'a']) {
        return false;
      }
      current = current->children[letter - 'a'];
    }
    return current->isEndOfWord;
  }
  bool startsWithPrefix(std::string prefix) {
    TrieNode *current = root;
    for (char letter : prefix) {
      int nodeIdx = letter - 'a';
      if (!current->children[nodeIdx]) {
        return false;
      }
      current = current->children[nodeIdx];
    }
    return true;
  }
};
