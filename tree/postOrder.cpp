#include<iostream>
#include<vector>
#include<stack>
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
void postOrder(Node* root) {
  vector<int> result;
  stack<Node*> st;
  while(root || !st.empty()) {
    if(!root) {
      root = st.top();
      st.pop();
      root = root->right;
      result.push_back(root->data);
    } else {
      st.push(root);
      root = root->left;
    }
  }

  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
}
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
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(9, root);
  root = insert(12, root);
  root = insert(3, root);
  root = insert(6, root);
  postOrder(root);
  return 0;
}
