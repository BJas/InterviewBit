#include<iostream>
#include<vector>
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
void dfs(Node* root) {
  if(!root) return;
  dfs(root->left);
  cout<<root->data<<" ";
  dfs(root->right);
}
Node* getBST(vector<int> a, int start, int end) {
  int mid = (start + end)/2;

  if(start > end) return NULL;
  Node* root = new Node(a[mid]);

  root->left = getBST(a, start, mid - 1);
  root->right = getBST(a, mid + 1, end);

  return root;

}
int main() {
  int n, x;
  cin>>n;
  vector<int> a;
  for(int i=0; i<n; i++) {
    cin >> x;
    a.push_back(x);
  }
  Node* root = getBST(a, 0, n-1);
  dfs(root);
  return 0;
}
