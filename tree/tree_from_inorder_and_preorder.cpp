#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct TreeNode {
  int data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int data) {
    this->data = data;
    left = right = NULL;
  }
};
void bfs(TreeNode* root) {
  if(!root) return;
  cout<<root->data<<" ";
  bfs(root->left);
  bfs(root->right);
}
TreeNode* constructTree(const vector<int> &inorder, const vector<int> &preorder,
                        int* index, map<int, int> &m, int left, int right) {
  if(left>right) return NULL;

  int curr = preorder[*index];
  TreeNode* root = new TreeNode(curr);
  (*index)++;
  if(left == right) return root;

  int iIndex = m[curr];
  root->left = constructTree(inorder, preorder, index, m, left, iIndex - 1);
  root->right = constructTree(inorder, preorder, index, m, iIndex + 1, right);

  return root;
}
int main() {
  int n, x;
  cin>>n;
  vector<int> inorder, preorder;
  for(int i=0; i<n; i++) {
    cin>>x;
    preorder.push_back(x);
  }
  for(int i=0; i<n; i++) {
    cin>>x;
    inorder.push_back(x);
  }
  int index = 0;
  map<int, int> m;
  for(int i=0; i<n; i++)
    m[inorder[i]] = i;
  TreeNode* root = constructTree(inorder, preorder, &index, m, 0, n-1);
  bfs(root);
  return 0;
}
