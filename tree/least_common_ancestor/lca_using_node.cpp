#include<iostream>
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
Node* lca(Node* root, int firstValue, int secondValue, bool &val1, bool &val2) {
  if(!root) return root;

  if(root->data == firstValue) {
    val1 = true;
    return root;
  }
  if(root->data == secondValue) {
    val2 = true;
    return root;
  }

  Node* leftNode = lca(root->left, firstValue, secondValue, val1, val2);
  Node* rightNode = lca(root->right, firstValue, secondValue, val1, val2);

  if(leftNode && rightNode) return root;

  return leftNode ? leftNode : rightNode;
}
bool findLca(Node* root, int B) {
    if(!root) return false;

    if(root->data == B || findLca(root->left, B) || findLca(root->right, B))
       return true;

   return false;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(9, root);
  root = insert(15, root);
  root = insert(17, root);
  root = insert(8, root);
  bool v1 = false, v2 = false;
  Node* result = lca(root, 8, 10, v1, v2);
  if(v1 && v2 || v2 && findLca(root, 8) || v1 && findLca(root, 10)) {
    cout<<result->data;
  } else {
    cout<<"NOT FOUND";
  }
  return 0;
}
