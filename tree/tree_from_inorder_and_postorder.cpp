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
void inorderbfs(Node* root) {
  if(!root) return;
  inorderbfs(root->left);
  cout<<root->data<<" ";
  inorderbfs(root->right);
}
void postorderbfs(Node* root) {
  if(!root) return;
  postorderbfs(root->left);
  postorderbfs(root->right);
  cout<<root->data<<" ";
}
Node* constructTree(const vector<int> &inorder, const vector<int> &postorder,
                    int* index, int left, int right, map<int, int> &m) {
  if(left > right) return NULL;

  int current = postorder[*index];
  Node* node = new Node(current);
  (*index)--;

  if(left == right) return node;

  int elementIndex = m[current];
  node->right = constructTree(inorder, postorder, index, elementIndex + 1, right, m);
  node->left = constructTree(inorder, postorder, index, left, elementIndex - 1, m);

  return node;
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
  for(int i=0; i<n; i++)
    m[inorder[i]] = i;
  int index = n-1;
  Node* root = constructTree(inorder, postorder, &index, 0, n-1, m);
  inorderbfs(root);
  cout<<endl;
  postorderbfs(root);
  return 0;
}
