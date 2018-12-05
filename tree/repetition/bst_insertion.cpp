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
  Node* node = new Node(data);
  if(!root) {
    return node;
  }
  Node *parent, *current = root;
  while(current) {
    parent = current;
    if(data <= current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  if(data <= parent->data) {
    parent->left = node;
  } else {
    parent->right = node;
  }
  return root;
}
void bfs(Node* root) {
  if(!root) return;
  bfs(root->left);
  cout<<root->data<<" ";
  bfs(root->right);
}
int main() {
  Node* root = NULL;
  root = insert(15, root);
  root = insert(10, root);
  root = insert(17, root);
  root = insert(20, root);
  root = insert(6, root);
  bfs(root);
  return 0;
}
