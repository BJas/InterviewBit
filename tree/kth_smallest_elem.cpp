#include<iostream>
#include<stack>
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
int inorder(Node* root, int index) {
  if(!root) return -1;
  stack<Node*> st;
  while(!st.empty() || root) {
    if(!root) {
      root = st.top();
      st.pop();
      index--;
      if(index == 0) {
        return root->data;
      }
      root = root->right;
    } else {
      st.push(root);
      root = root->left;
    }
  }
  return -1;
}
int recursive(Node* root, int &index) {
  if(!root) return -1;
  int k = recursive(root->left, index);
  cout<<k<<endl;
  if(index==0) return k;
  index--;
  if(index==0) return root->data;
  return recursive(root->right, index);
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(8, root);
  root = insert(9, root);
  root = insert(2, root);
  root = insert(16, root);
  int k;
  cin>>k;
  cout<<recursive(root, k);
  return 0;
}
