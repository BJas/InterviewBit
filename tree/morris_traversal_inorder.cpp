#include<iostream>
#include<vector>
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
Node* findPredecessor(Node* root) {
  Node* pre = root->left;
  while(pre->right && pre->right != root) {
    pre = pre->right;
  }
  return pre;
}
void morrisTraversal(Node* root) {
  if(!root) return;
  vector<int> result;
  while(root) {
    if(!root->left) {
      result.push_back(root->data);
      root = root->right;
    } else {
      Node* predecessor = findPredecessor(root);
      if(!predecessor->right) {
        predecessor->right = root;
        root = root->left;
      } else {
        predecessor->right = NULL;
        result.push_back(root->data);
        root = root->right;
      }
    }
  }

  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(6, root);
  root = insert(5, root);
  root = insert(12, root);
  root = insert(17, root);
  morrisTraversal(root);
  return 0;
}
