#include<iostream>
using namespace std;
struct Node {
  int data;
  Node *left, *right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};
Node* insert(int data, Node *root) {
  Node *current = new Node(data);
  if(!root) {
    return current;
  }
  Node *parent, *node = root;
  while(node) {
    parent = node;
    if(data <= node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }

  if(data <= parent->data) {
    parent->left = current;
  } else {
    parent->right = current;
  }

  return root;
}
bool isSame(Node* firstNode, Node* secondNode) {
  if(!firstNode && !secondNode) return true;
  if(!firstNode || !secondNode) return false;

  return firstNode->data == secondNode->data
         && isSame(firstNode->left, secondNode->left)
         && isSame(firstNode->right, secondNode->right);
}
int main() {
  Node* root = NULL;
  root = insert(15, root);
  root = insert(10, root);
  root = insert(17, root);
  root = insert(20, root);
  root = insert(6, root);
  Node* root2 = NULL;
  root2 = insert(15, root2);
  root2 = insert(10, root2);
  root2 = insert(17, root2);
  root2 = insert(21, root2);
  root2 = insert(6, root2);
  cout<<isSame(root, root2);
  return 0;
}
