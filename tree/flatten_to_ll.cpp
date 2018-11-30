#include<iostream>
using namespace std;
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int val) {
    this->val = val;
    left = right = NULL;
  }
};
Node* insert(int data, Node* root) {
  Node* current = new Node(data);
  if(!root) {
    root = current;
  } else if(data <= root->val) {
    root->left = insert(data, root->left);
  } else {
    root->right = insert(data, root->right);
  }
  return root;
}
void flatten(Node* root) {
  if(!root || (!root->left && !root->right)) return;
  if(root->left) {
    flatten(root->left);
    Node* rightTemp = root->right;
    root->right = root->left;
    root->left = NULL;

    Node* temp = root->right;
    while(temp->right) {
      temp = temp->right;
    }

    temp->right = rightTemp;
  }
  flatten(root->right);
}
void dfs(Node* root) {
  if(!root) return;
  // dfs(root->left);
  cout<<root->val<<" ";
  dfs(root->right);
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(6, root);
  root = insert(8, root);
  root = insert(5, root);
  root = insert(17, root);
  flatten(root);
  dfs(root);
  return 0;
}
