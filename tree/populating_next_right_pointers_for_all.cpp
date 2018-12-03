#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node* next;
  Node(int data) {
    this->data = data;
    left = right = next = NULL;
  }
};
Node* insert(Node* root, int data) {
  Node* current = new Node(data);
  if(!root) {
    root = current;
  } else if(data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}
Node* getNextRight(Node* root) {
  root = root->next;
  while(root) {
    if(root->left)
      return root->left;
    if(root->right)
      return root->right;
     root = root->next;
  }
  return NULL;
}
void populate(Node* root) {

  if(!root) return;

  if(root->next)
    populate(root->next);

  if(root->left) {
      if(root->right) {
        root->left->next = root->right;
        root->right->next = getNextRight(root);
      } else {
        root->left->next = getNextRight(root);
      }
      populate(root->left);
  } else if(root->right) {
    root->right->next = getNextRight(root);
    populate(root->right);
  } else
    populate(getNextRight(root));
}

void dfs(Node* root) {
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    Node* current = q.front();
    q.pop();
    if(current->next)
    cout<<current->next->data<<" ";
    else
    cout<<"x"<<" ";
    if(current->left)
      q.push(current->left);
    if(current->right)
      q.push(current->right);
  }
}
int main() {
  Node* root = NULL;
  root = insert(root, 10);
  root = insert(root, 8);
  root = insert(root, 12);
  root = insert(root, 6);
  root = insert(root, 5);
  root = insert(root, 21);
  populate(root);
  dfs(root);
  return 0;
}
