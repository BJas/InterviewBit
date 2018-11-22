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
Node* find(Node* root, int data) {

  if(!root) return root;

  if(data == root->data) return root;
  else if(data < root->data) return find(root->left, data);

  return find(root->right, data);
}
Node* GetSuccessor(Node* root, int data) {

  if(!root) return root;

  Node* current = find(root, data);

  if(current->right) {
    Node* tempRight = current->right;
    while(tempRight->left) tempRight = tempRight->left;
    return tempRight;
  } else {
    Node* successor = NULL;
    Node* ancestor = root;
    while(ancestor != current) {
      if(current->data < ancestor->data) {
        successor = ancestor;
        ancestor = ancestor->left;
      } else {
        ancestor = ancestor->right;
      }
    }
    return successor;
  }
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(15, root);
  root = insert(6, root);
  root = insert(8, root);
  Node* result =  GetSuccessor(root, 6);
  cout<<result->data;
  return 0;
}
