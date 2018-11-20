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

int searchMax(Node* root) {
  if(!root) return -1;
  while(root->right) {
    root = root->right;
  }
  return root->data;
}

int searchMin(Node* root) {
  if(!root) return -1;
  else if(!root->left) return root->data;
  return searchMin(root->left);
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(18, root);
  root = insert(15, root);
  root = insert(12, root);
  root = insert(7, root);
  root = insert(16, root);
  cout<<searchMax(root)<<endl;
  cout<<searchMin(root)<<endl;
  return 0;
}
