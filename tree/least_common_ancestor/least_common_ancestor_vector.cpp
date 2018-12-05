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
bool lca(Node* root, int value, vector<int> &first) {
  if(!root) return false;
  first.push_back(root->data);
  if(root->data == value) return true;
  if (lca(root->left, value, first)
      || lca(root->right, value, first))
      return true;
  first.pop_back();
  return false;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(8, root);
  root = insert(9, root);
  root = insert(2, root);
  root = insert(16, root);
  int first, second;
  cin>>first>>second;
  vector<int> v, v1;
  if(lca(root, first, v) && lca(root, second, v1)) {
    int i;
    for(i = 0; i < v.size() && i < v1.size(); i++)
      if(v[i] != v1[i])
        break;
    cout<<v[i-1];
  }
  return 0;
}
