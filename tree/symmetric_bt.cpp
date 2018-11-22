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
bool isMirror(Node* first, Node* second) {
  if(!first && !second) return true;
  if(first && second) {
    return first->data == second->data &&
    isMirror(first->left, second->right) &&
    isMirror(first->right, second->left);
  }
  return false;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(11, root);
  root = insert(15, root);
  root = insert(7, root);
  cout<<isMirror(root, root);
  return 0;
}
