#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define MAX_SIZE 26
struct Node {
  Node* child[MAX_SIZE];
  int index;            //without duplicates
  vector<int> indexes;  //for duplicates
  Node() {
    for(int i = 0; i < MAX_SIZE; i++)
      child[i] = NULL;
    index = -1;
  }
};
Node* insert(string word, Node* root, int index) {
  if(!root) {
    root = new Node();
    root->child[word[0] - 'a'] = NULL;
  }
  Node* current = root;
  for(int i=0; i<word.size(); i++) {
    char ch = word[i] - 'a';
    Node* node = current->child[ch];

    if(!node) {
      node = new Node();
      current->child[ch] = node;
    }

    current = node;
  }

  // current->index = index;
  (current->indexes).push_back(index);
  return root;
}
void sort(Node* root, const vector<string> &str) {
  if(!root) return;
  for(int i=0; i<MAX_SIZE; i++) {
    if(root->child[i]) {
      // TO GET UNIQUE
      // if(root->child[i]->index != -1) {
      //   cout<<str[root->child[i]->index]<<" ";
      // }
      if(root->child[i]->indexes.size() != 0) {
        for(int j=0; j<root->child[i]->indexes.size(); j++) {
          cout<<str[root->child[i]->indexes[j]]<<" ";
        }
      }
      sort(root->child[i], str);
    }
  }
}
int main() {
  int n;
  cin>>n;
  vector<string> str;
  string s;

  for(int i=0; i<n; i++) {
    cin>>s;
    str.push_back(s);
  }

  Node* root = NULL;

  for(int i=0; i<n; i++)
    root = insert(str[i], root, i);
  sort(root, str);
  return 0;
}
