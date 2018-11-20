#include<iostream>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
};
Node* getNewNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
Node* insert(int data, Node* root) {
  Node* current = getNewNode(data);
  if(!root) {
    root = current;
  } else if(data <= root->data) {
    root->left = insert(data, root->left);
  } else {
    root->right = insert(data, root->right);
  }
  return root;
}
void preOrder(Node* root) {
  if(!root) return;
  preOrder(root->left);
  cout<<root->data<<" ";
  preOrder(root->right);
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(8, root);
  root = insert(15, root);
  root = insert(21, root);
  preOrder(root);
  return 0;
}
