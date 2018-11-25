#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int data) {
    this->val = data;
    left = right = NULL;
  }
};
Node* insert(int data, Node* root) {
  Node* current = new Node(data);
  if(!root) {
    root = current;
  } else if(data <= root->val) {
    root->left = insert(data, root->left);
  } else {
    root->right = insert(data, root->right);
  }
  return root;
}
bool getPathSum(Node* root, int target, int sum) {
  if(!root) return false;
  bool ans = false;
  sum += root->val;
  if(sum == target && !root->left && !root->right) return true;
  ans = ans || getPathSum(root->left, target, sum);
  ans = ans || getPathSum(root->right, target, sum);
  return ans;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(6, root);
  root = insert(8, root);
  root = insert(5, root);
  root = insert(17, root);
  cout<<getPathSum(root, 39, 0);
  cout<<getPathSum(root, 300, 0);
  cout<<getPathSum(root, 21, 0);
  return 0;
}
