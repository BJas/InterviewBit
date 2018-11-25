#include<iostream>
#include<stack>
#include<map>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};

Node* insert(int data, Node* root) {
  Node* current = new Node(data);
  if(!root) {
    root = current;
  } else if(data <= root->data) {
    root->left = insert(data, root->left);
  } else {
    root->right = insert(data, root->right);
  }
  return root;
}
bool findPair(Node* root, map<int, bool> &m, int target) {

  if(!root) return false;

  if (findPair(root->left, m, target))
    return true;

  if(m.find(target-(root->data)) != m.end())
    return true;
  else
    m[root->data] = true;

  return findPair(root->right, m, target);
}
int main() {
  Node* root = NULL;
  root = insert(15, root);
  root = insert(10, root);
  root = insert(17, root);
  root = insert(20, root);
  root = insert(6, root);
  map<int, bool> m;
  int k;
  cin>>k;
  cout<<findPair(root, m, k);
  return 0;
}
