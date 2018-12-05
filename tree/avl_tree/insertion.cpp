#include<iostream>
using namespace std;
struct Node {
  int data;
  Node *left, *right;
  int height;
  Node(int data) {
    this->data = data;
    left = right = NULL;
    height = 1;
  }
};
int height(Node* root) {
  if(!root) return 0;
  return root->height;
}
int getBalance(Node* root) {
  if(!root) return 0;
  return height(root->left) - height(root->right);
}
Node* rightRotate(Node* root) {
  Node* leftNode = root->left;
  root->left = leftNode->right;
  leftNode->right = root;
  root->height = max(height(root->left), height(root->right)) + 1;
  leftNode->height = max(height(leftNode->left), height(leftNode->right)) + 1;
  return leftNode;
}
Node* leftRotate(Node* root) {
  Node* rightNode = root->right;
  root->right = rightNode->left;
  rightNode->left = root;
  root->height = max(height(root->left), height(root->right)) + 1;
  rightNode->height = max(height(rightNode->left), height(rightNode->right)) + 1;
  return rightNode;
}
Node* insertion(Node *root, int data) {
  if(!root) {
    return new Node(data);
  } else if(data < root->data) {
    root->left = insertion(root->left, data);
  } else if(data > root->data) {
    root->right = insertion(root->right, data);
  } else {
    return root;
  }
  root->height = max(height(root->left), height(root->right)) + 1;


  int balance = getBalance(root);

  //LEFT LEFT
  if(balance > 1 && data < root->left->data) {
    return rightRotate(root);
  }

  //LEFT RIGHT
  if(balance > 1 && data > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  //RIGHT RIGHT
  if(balance < -1 && data > root->right->data) {
    return leftRotate(root);
  }

  //RIGHT LEFT
  if(balance < -1 && data < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}
void bfs(Node* root) {
  if(!root) return;
  cout<<root->data<<" ";
  bfs(root->left);
  bfs(root->right);
}
int main() {
  Node *root = NULL;
  root = insertion(root, 10);
  root = insertion(root, 20);
  root = insertion(root, 30);
  root = insertion(root, 40);
  root = insertion(root, 50);
  root = insertion(root, 25);
  bfs(root);
  return 0;
}
