#include<iostream>
#include<cmath>
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
int FindHeight(Node* root) {
   if(!root)
    return -1;
    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(18, root);
  root = insert(20, root);
  root = insert(22, root);
  root = insert(27, root);
  root = insert(21, root);
  cout<<FindHeight(root)<<endl;
  return 0;
}
