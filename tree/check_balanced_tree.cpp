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

bool check(Node* root, int &height) {

  int lh = 0, rh = 0;

  if(!root) {
    height = 0;
    return 1;
  }

  bool l = check(root->left, height);
  bool r = check(root->right, height);

  height = max(lh, rh) + 1;

  if(abs(lh - rh) > 2)
    return 0;
  else
    return l&&r;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(15, root);
  root = insert(17, root);
  root = insert(8, root);
  int height = 0;
  cout<<check(root, height);
  return 0;
}
