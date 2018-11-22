#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data) {
    this->data =data;
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
void preorder(Node* root) {
  vector<int> result;
  stack<Node*> q;
  q.push(root);
  while(!q.empty()) {
    root = q.top();
    q.pop();
    while(root) {
      result.push_back(root->data);
      if(root->right) q.push(root->right);
      root = root->left;
    }
  }
  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
}
void recursivePreorder(Node* root) {
  if(!root) return;
  cout<<root->data<<" ";
  recursivePreorder(root->left);
  recursivePreorder(root->right);
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(9, root);
  root = insert(12, root);
  root = insert(3, root);
  root = insert(6, root);
  recursivePreorder(root);
  cout<<endl;
  preorder(root);
  return 0;
}

//root, left, right
