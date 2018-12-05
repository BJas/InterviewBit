#include<iostream>
#include<map>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node* parent;
  Node(int data) {
    this->data = data;
    left = right = parent = NULL;
  }
};
Node* insert(int data, Node* root) {
  Node* current = new Node(data);
  if(!root) {
    root = current;
  } else if(data <= root->data) {
    root->left = insert(data, root->left);
    root->left->parent = root;
  } else {
    root->right = insert(data, root->right);
    root->right->parent = root;
  }
  return root;
}
Node* findLca(Node* root, int value) {
  if(!root) return root;

  if(root->data == value) return root;

  if(findLca(root->left, value) || findLca(root->right, value))
    return root;

  return NULL;
}
Node* lca(Node* firstNode, Node* secondNode) {
  map<Node*, bool> m;
  while(firstNode) {
    m[firstNode] = true;
    firstNode = firstNode->parent;
  }

  while (secondNode) {
    if(m.find(secondNode) != m.end())
      return secondNode;
    secondNode = secondNode->parent;
  }
  return NULL;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(9, root);
  root = insert(15, root);
  root = insert(17, root);
  root = insert(8, root);
  Node* first = findLca(root, 9);
  Node* second = findLca(root, 10);
  Node* result = lca(first, second);
  cout<<result->data;
  return 0;
}
