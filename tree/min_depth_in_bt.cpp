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
  Node* newNode = new Node(data);
  if(!root) {
    root = newNode;
  } else if(data <= root->data) {
    root->left = insert(data, root->left);
  } else {
    root->right = insert(data, root->right);
  }
  return root;
}
int minDepth(Node* root) {
  if(!root) return 0;
  else if(!root->left && !root->right) return 1;
  else if(!root->left) return minDepth(root->right) + 1;
  else if(!root->right) return minDepth(root->left) + 1;
  return min(minDepth(root->left), minDepth(root->right)) + 1;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(9, root);
  root = insert(8, root);
  root = insert(3, root);
  root = insert(6, root);
  cout<<minDepth(root);
  return 0;
}
