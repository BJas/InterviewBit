#include<iostream>
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
int getSum(Node* root) {
  if(!root) return 0;
  stack<pair<Node*, long long int> > st;
  long long int total = 0;
  st.push(make_pair(root, root->data));
  while(!st.empty()) {
    pair<Node*, long long int> p = st.top();
    Node* currentNode = p.first;
    st.pop();
    if(!currentNode->left && !currentNode->right)
      total = (total + p.second)%1003;
    if(currentNode->left)
      st.push(make_pair(currentNode->left, (p.second*10+currentNode->left->data)%1003));
    if(currentNode->right)
      st.push(make_pair(currentNode->right, (p.second*10+currentNode->right->data)%1003));
  }
  return total;
}
int recursiveGetSum(Node* root, int sum) {
  if(!root) return sum;
  sum = sum*10 + root->data;
  if(!root->left && !root->right) return sum;
  if(!root->left) return recursiveGetSum(root->right, sum);
  if(!root->right) return recursiveGetSum(root->left, sum);
  return recursiveGetSum(root->left, sum) + recursiveGetSum(root->right, sum);
}
int main() {
  Node* root = NULL;
  root = insert(3, root);
  root = insert(2, root);
  root = insert(5, root);
  cout<<recursiveGetSum(root, 0)<<endl;
  return 0;
}
