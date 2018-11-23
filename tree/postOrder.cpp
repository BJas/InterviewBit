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
  stack<int> resultSt;
  st.push(root);
  while(!st.empty()) {
    root = st.top();
    st.pop();
    resultSt.push(root->data);
    if(root->left) st.push(root->left);
    if(root->right) st.push(root->right);
  }
  while(!resultSt.empty()) {
    result.push_back(resultSt.top());
    resultSt.pop();
  }

  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
}
void recursivePostorder(Node* root) {
  if(!root) return;
  recursivePostorder(root->left);
  recursivePostorder(root->right);
  cout<<root->data<<" ";
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
  cout<<endl;
  recursivePostorder(root);
  return 0;
}
