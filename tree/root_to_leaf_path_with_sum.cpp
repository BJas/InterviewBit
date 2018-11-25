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
void getSum(Node* root, vector<vector<int> > &result, vector<int> &currentSum, int target) {
  if(!root) return;
  currentSum.push_back(root->data);
  target -= root->data;
  if(!root->left && !root->right && target == 0) {
    result.push_back(currentSum);
  }
  getSum(root->left, result, currentSum, target);
  getSum(root->right, result, currentSum, target);
  currentSum.pop_back();
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(13, root);
  root = insert(6, root);
  root = insert(7, root);
  vector<vector<int> > result;
  vector<int> currentSum;
  getSum(root, result, currentSum, 23);
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++) {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
