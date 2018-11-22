#include<iostream>
#include<stack>
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
void inorder(Node* root) {
  stack<Node*> st;
  vector<int> result;
  while(!st.empty() || root) {
    if(!root) {
      root = st.top();
      st.pop();
      result.push_back(root->data);
      root = root->right;
    } else {
      st.push(root);
      root = root->left;
    }
  }
  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(9, root);
  root = insert(12, root);
  root = insert(3, root);
  root = insert(6, root);
  inorder(root);
  return 0;
}
