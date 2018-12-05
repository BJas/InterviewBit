#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct TrieNode {
  map<char, pair<TrieNode*, int> > children;
};

TrieNode* insert(TrieNode* root, string word) {
  if(!root) {
    root = new TrieNode();
    root->children[word[0]].first = NULL;
  }
  TrieNode* current = root;
  for(int i=0; i<word.size(); i++) {
    char ch = word[i];
    TrieNode* node = current->children[ch].first;
    if(!node) {
      node = new TrieNode();
      current->children[ch].first = node;
    }
    current->children[ch].second++;
    current = node;
  }
  return root;
}
string search(TrieNode* root, string word) {
  string prefix = "";
  if(!root) return prefix;
  for(int i=0; i<word.size(); i++) {
    prefix += word[i];
    if(root->children.find(word[i]) == root->children.end() || root->children[word[i]].second == 1) {
      return prefix;
    }
    root = root->children[word[i]].first;
  }
  return prefix;
}
int main() {
  int n;
  cin>>n;
  vector<string> str;
  string x;
  for(int i=0; i<n; i++) {
    cin>>x;
    str.push_back(x);
  }
  TrieNode* root = NULL;
  for(int i=0; i<n; i++) {
    root = insert(root, str[i]);
  }
  for(int i=0; i<n; i++) {
    cout<<search(root, str[i])<<endl;
  }
  return 0;
}
