#include<iostream>
#include<queue>
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
bool isIdentical(Node* first, Node* second) {
  if(!first && !second) return true;
  if(first && second) {
    return first->data == second->data &&
    isIdentical(first->left, second->left) &&
    isIdentical(first->right, second->right);
  }
  return false;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(8, root);
  root = insert(11, root);
  Node* root1 = NULL;
  root1 = insert(10, root1);
  root1 = insert(12, root1);
  root1 = insert(8, root1);
  root1 = insert(11, root1);
  cout<<isIdentical(root, root1);
  return 0;
}
