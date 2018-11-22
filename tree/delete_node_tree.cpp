#include<iostream>
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
Node* FindMin(Node* root) {
  while(root->left)
    root = root->left;
  return root;
}
Node* Delete(Node* root, int data) {
  if(!root) return root;
  else if(data < root->data) root->left = Delete(root->left, data);
  else if(data > root->data) root->right = Delete(root->right, data);
  else {
    if(!root->left && !root->right) {
      delete root;
      root = NULL;
      return root;
    } else if(!root->left) {
      Node* current = root;
      root = root->right;
      delete current;
    } else if(!root->right) {
      Node* current = root;
      root = root->left;
      delete current;
    } else {
      Node* temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}
void dfs(Node* root) {
  if(!root) return;
  dfs(root->left);
  cout<<root->data<<" ";
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
  Node* result = Delete(root, 10);
  dfs(root);
  return 0;
}
