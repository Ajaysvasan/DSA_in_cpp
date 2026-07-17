#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  vector<TrieNode *> children;
  bool isEndOfWord;
  TrieNode() {
    children.resize(26);
    isEndOfWord = false;
  }
};

class Trie {
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }
  void insert(string word) {
    TrieNode *current = root;
    for (char letter : word) {
      int nodeIdx = letter - 'a';
      if (!current->children[nodeIdx]) {
        current->children[nodeIdx] = new TrieNode();
      }
      current = current->children[nodeIdx];
    }
    current->isEndOfWord = true;
  }
  bool search(string word) {
    TrieNode *current = root;
    for (char letter : word) {
      int nodeIdx = letter - 'a';
      if (!current->children[nodeIdx]) {
        return false;
      }
      current = current->children[nodeIdx];
    }
    return current->isEndOfWord;
  }
  void dfs(vector<string> &combination, string &prevWord, TrieNode *node) {
    // if (combination.size() == 3)
    //   return;
    if (node->isEndOfWord) {
      combination.push_back(prevWord);
    }
    for (int i = 0; i < 26; i++) {
      if (!node->children[i]) {
        continue;
      }
      prevWord.push_back(i + 'a');
      dfs(combination, prevWord, node->children[i]);
      prevWord.pop_back();
      // if (combination.size() == 3)
      //   return;
    }
  }
  vector<string> findWords(string query) {
    TrieNode *current = root;
    for (char letter : query) {
      int nodeIdx = letter - 'a';
      if (!current->children[nodeIdx]) {
        return {};
      }
      current = current->children[nodeIdx];
    }
    vector<string> words;
    dfs(words, query, current);
    return words;
  }
};

class Solution {
public:
  vector<vector<string>> productSuggestion(vector<string> &products,
                                           string searchWord) {
    Trie trie;
    for (string product : products) {
      trie.insert(product);
    }
    vector<vector<string>> res;
    string currentQuery = "";
    for (char letter : searchWord) {
      currentQuery += letter;
      res.push_back(trie.findWords(currentQuery));
    }
    return res;
  }
};
