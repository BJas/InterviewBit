#include<iostream>
#include<map>
#include<string>
using namespace std;
struct TrieNode {
  map<char, TrieNode*> children;
  bool isEndOfWord;
  TrieNode() {
    isEndOfWord = false;
  }
};
TrieNode* insert(string word, TrieNode* root) {

  if(!root) {
    root = new TrieNode();
    root->children[word[0]] = NULL;
  }

  TrieNode* current = root;

  for(int i=0; i<word.length(); i++) {
    char ch = word[i];
    TrieNode* node = current->children[ch];
    if(!node) {
      node = new TrieNode();
      current->children[ch] = node;
    }
    current = node;
  }
  current->isEndOfWord = true;

  return root;
}
void recursiveInsert(string word, TrieNode* root, int index) {
  if(index == word.length()) {
    root->isEndOfWord = true;
    return;
  }

  char ch = word[index];
  TrieNode* current = root->children[ch];
  if(!current) {
    current = new TrieNode();
    root->children[ch] = current;
  }

  recursiveInsert(word, current, index + 1);
}
bool search(string word, TrieNode* root) {
  TrieNode* current = root;
  for(int i=0; i<word.length(); i++) {
    char ch = word[i];

    if(current->children.find(ch) == current->children.end())
      return false;

    current = current->children[ch];
  }
  return current->isEndOfWord;
}
bool recursiveSearch(string word, TrieNode* root, int index) {
  if(word.length() == index)
    return root->isEndOfWord;

  if(root->children.find(word[index]) == root->children.end())
    return false;

  return recursiveSearch(word, root->children[word[index]], index + 1);
}
bool deleteWord(string word, TrieNode* current, int index) {
  if(index == word.length()) {
    if(!current->isEndOfWord)
      return false;

    current->isEndOfWord = true;
    return current->children.size() == 0;
  }

  char ch = word[index];
  TrieNode* node = current->children[ch];

  if(!node) return false;

  bool isToDelete = deleteWord(word, node, index + 1);

  if(isToDelete) {
    current->children.erase(ch);
    return current->children.size() == 0;
  }

  return false;
}
int main() {
  TrieNode* root = NULL;
  root = insert("kazakh", root);
  cout<<search("kazakh", root)<<endl;
  cout<<recursiveSearch("kazakh", root, 0)<<endl;
  return 0;
}
