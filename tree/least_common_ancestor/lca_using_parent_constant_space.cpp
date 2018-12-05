#include<iostream>
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
int depth(Node* node) {
  if(!node) return 0;
  int depth = -1;
  while(node) {
    depth++;
    node = node->parent;
  }
  return depth;
}
Node* findLca(Node* root, int value) {
  if(!root) return root;
  if(root->data == value) return root;

  if(findLca(root->left, value) || findLca(root->right, value))
    return root;
  return NULL;
}
Node* lca(Node* firstNode, Node* secondNode) {
  int firstDepth = depth(firstNode);
  int secondDepth = depth(secondNode);
  int diff = firstDepth - secondDepth;
  if(diff < 0) {
    Node* tempNode = firstNode;
    firstNode = secondNode;
    secondNode = tempNode;
    diff = -diff;
  }
  while(diff--) {
    firstNode = firstNode->parent;
  }

  while(firstNode && secondNode) {
    if(firstNode == secondNode)
      return firstNode;
    firstNode = firstNode->parent;
    secondNode = secondNode->parent;
  }
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(9, root);
  root = insert(15, root);
  root = insert(17, root);
  root = insert(8, root);
  Node* first = findLca(root, 9);
  Node* second = findLca(root, 27);
  Node* result = lca(first, second);
  if(result) {
    cout<<result->data;
  } else {
    cout<<"NOT FOUND";
  }
  return 0;
}
