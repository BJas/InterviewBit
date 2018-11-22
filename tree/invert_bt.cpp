#include<iostream>
#include<queue>
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
Node* invert(Node* root) {
  if(!root) return root;
  root->left = invert(root->left);
  root->right = invert(root->right);
  Node* temp = root->left;
  root->left = root->right;
  root->right = temp;
  return root;
}
void bfs(Node* root) {
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    Node* temp = q.front();
    cout<<temp->data<<" ";
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
    q.pop();
  }
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(5, root);
  root = insert(12, root);
  root = insert(15, root);
  root = insert(6, root);
  root = insert(8, root);
  bfs(root);
  cout<<endl;
  Node* result = invert(root);
  bfs(result);
  return 0;
}
