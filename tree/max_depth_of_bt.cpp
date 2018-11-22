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
int height(Node* root) {
  if(!root) return 0;
  return max(height(root->left), height(root->right)) + 1;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(8, root);
  root = insert(7, root);
  root = insert(2, root);
  root = insert(6, root);
  cout<<height(root);
  return 0;
}
