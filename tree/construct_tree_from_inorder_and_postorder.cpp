#include<iostream>
#include<vector>
#include<map>
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
void inorderTraverse(Node* root) {
  if(!root) return;
  cout<<root->data<<" ";
  inorderTraverse(root->left);
  inorderTraverse(root->right);
}
Node* structTree(const vector<int> &inorder, const vector<int> &postorder,
                 int left, int right, map<int, int> &m, int* r) {
  if(left > right) return NULL;

  int curr = postorder[*r];
  Node* temp = new Node(curr);
  (*r)--;

  if(left == right) return temp;

  int index = m[curr];

  temp->right = structTree(inorder, postorder, index + 1, right, m, r);
  temp->left = structTree(inorder, postorder, left, index - 1, m, r);

  return temp;
}
int main() {
  int n, x;
  cin>>n;
  vector<int> inorder, postorder;
  for(int i=0; i<n; i++) {
    cin>>x;
    inorder.push_back(x);
  }
  for(int i=0; i<n; i++) {
    cin>>x;
    postorder.push_back(x);
  }
  map<int, int> m;
  for(int i=0; i<n; i++) {
    m[inorder[i]] = i;
  }
  int r = n-1;
  Node* root = structTree(inorder, postorder, 0, n-1, m, &r);
  inorderTraverse(root);
  return 0;
}
