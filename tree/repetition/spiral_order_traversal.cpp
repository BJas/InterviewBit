#include<iostream>
#include<vector>
#include<stack>
#include<deque>
using namespace std;
struct Node {
  int data;
  Node *left, *right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};
Node* insert(int data, Node* root) {
  Node* current = new Node(data);
  if(!root) {
    return current;
  } else if(data <= root->data) {
    root->left = insert(data, root->left);
  } else {
    root->right = insert(data, root->right);
  }
  return root;
}
void traverseSpiral(Node* root) {
  if(!root) return;
  stack<Node*> evenSt;
  stack<Node*> oddSt;
  evenSt.push(root);
  int level  = 0;
  vector<int> result;
  while(!evenSt.empty() || !oddSt.empty()) {
    while(!evenSt.empty()) {
      Node* node = evenSt.top();
      evenSt.pop();
      result.push_back(node->data);
      if(node->left) oddSt.push(node->left);
      if(node->right) oddSt.push(node->right);
    }

    while(!oddSt.empty()) {
      Node* secondNode = oddSt.top();
      oddSt.pop();
      result.push_back(secondNode->data);
      if(secondNode->left) evenSt.push(secondNode->left);
      if(secondNode->right) evenSt.push(secondNode->right);
    }
  }
  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
}
void traverseSpiralUsingDeque(Node* root) {
  if(!root) return;
  deque <Node*> d;
  d.push_front(root);
  d.push_back(NULL);
  vector<int> result;
  while(d.front() || d.back()) {
    Node* node = d.front();
    while(node) {
      d.pop_front();
      result.push_back(node->data);
      if(node->left) d.push_back(node->left);
      if(node->right) d.push_back(node->right);
      node = d.front();
    }

    node = d.back();
    while(node) {
      d.pop_back();
      result.push_back(node->data);
      if(node->left) d.push_front(node->left);
      if(node->right) d.push_front(node->right);
      node = d.back();
    }
  }

  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
}
int main() {
  Node* root = NULL;
  root = insert(15, root);
  root = insert(10, root);
  root = insert(17, root);
  root = insert(20, root);
  root = insert(6, root);
  traverseSpiralUsingDeque(root);
  return 0;
}
