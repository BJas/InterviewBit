#include<iostream>
#include<queue>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node* next;
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
void bfs(Node* root) {
  if(!root) return;

  if(root->left)
    root->left->next = root->right;

  if(root->right)
    root->right->next = (root->next) ? root->next->left : NULL;

  bfs(root->left);
  bfs(root->right);
}
void bfsIterative(Node* root) {
  if(!root) return;

  queue<Node*> q;
  q.push(root);

  while(!q.empty()) {
    Node* curr = q.front();
    q.pop();
    cout<<curr->data<<" ";
    if(curr->next) cout<<curr->next->data<<endl;
    else cout<<"x"<<endl;
    if(curr->left) q.push(curr->left);
    if(curr->right) q.push(curr->right);
  }
}
void dfs(Node* root) {
  if(!root) return;
  dfs(root->left);
  cout<<root->data<<" ";
  dfs(root->right);
}
int main() {
  Node* root = NULL;
  root = insert(12, root);
  root = insert(8, root);
  root = insert(14, root);
  root = insert(6, root);
  root = insert(10, root);
  root = insert(13, root);
  root = insert(16, root);
  bfs(root);
  cout<<endl;
  bfsIterative(root);
  cout<<endl;
  dfs(root);
  return 0;
}
