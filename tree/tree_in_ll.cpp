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
bool search(int data, Node* root) {
  if(!root)
    return false;
  else if(root->data == data)
    return true;
  else if(data <= root->data)
    return search(data, root->left);
  else
    return search(data, root->right);
  return false;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(18, root);
  root = insert(15, root);
  root = insert(12, root);
  root = insert(7, root);
  root = insert(16, root);
  cout<<search(10, root)<<endl;
  cout<<search(12, root)<<endl;
  cout<<search(1, root)<<endl;

  return 0;
}
