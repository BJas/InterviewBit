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
  Node* curr = root->next;
  while (curr) {
    if(curr->left)
      return curr->left;
    if(curr->right)
      return curr->right;
    curr = curr->next;
  }
  return NULL;
}
void populate(Node* root) {

  if(!root) return;

  root->next = NULL;

  while(root) {
    Node* current = root;
    while(current) {
      if(current->left) {
        if(current->right) {
          current->left->next = current->right;
        } else {
          current->left->next = getNextRight(current);
        }
      }
      if(current->right) {
        current->right->next = getNextRight(current);
      }
      current = current->next;
    }
    if(root->left)
      root = root->left;
    else if(root->right)
      root = root->right;
    else
      root = getNextRight(root);
  }
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
  root = insert(root, 9);
  root = insert(root, 21);
  populate(root);
  dfs(root);
  return 0;
}
