#include<iostream>
#include<vector>
#include<cmath>
#include<map>
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

void inorderBFS(Node* root) {
  if(!root) return;
  inorderBFS(root->left);
  cout<<root->data<<" ";
  inorderBFS(root->right);
}
int getMax(const vector<int> &inorder, int left, int right) {
  int maxElement = inorder[left], index = left;

  for(int i = left + 1; i <= right; i++) {
    if(maxElement < inorder[i]) {
      maxElement = inorder[i];
      index = i;
    }
  }
  return index;
}
Node* constructCartesianTree(const vector<int> &inorder, int left, int right) {
  if(left > right) return NULL;

  int maxIndex = getMax(inorder, left, right);
  Node* node = new Node(inorder[maxIndex]);

  if(left == right) return node;

  node->left = constructCartesianTree(inorder, left, maxIndex - 1);
  node->right = constructCartesianTree(inorder, maxIndex + 1, right);

  return node;
}
int main() {
  int n, value;
  cin>>n;
  vector<int> inorder;
  for(int i = 0; i < n; i++) {
    cin>>value;
    inorder.push_back(value);
  }
  Node* root = constructCartesianTree(inorder, 0, n - 1);
  inorderBFS(root);
  return 0;
}
