#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data) {
    this->data = data;
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
void verticalTraverse(Node* root, int index, map<int, vector<int> > &result) {
  if(!root) return;
  result[index].push_back(root->data);
  verticalTraverse(root->left, index-1, result);
  verticalTraverse(root->right, index+1, result);
}
void verticalTraverseDFS(Node* root, map<int, vector<int> > &result) {
  queue<pair<Node*, int> > q;
  q.push(make_pair(root, 0));
  while(!q.empty()) {
    pair<Node*, int> current = q.front();
    q.pop();
    result[current.second].push_back(current.first->data);
    if(current.first->left)
      q.push(make_pair(current.first->left, current.second-1));
    if(current.first->right)
      q.push(make_pair(current.first->right, current.second+1));
  }
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(11, root);
  root = insert(15, root);
  root = insert(7, root);
  map<int, vector<int> > result;
  // verticalTraverse(root, 0, result);
  verticalTraverseDFS(root, result);
  map<int, vector<int> >::iterator point;
  for(point = result.begin(); point != result.end(); point++) {
    vector<int> res = point->second;
    for(int i=0; i<res.size(); i++)
      cout<<res[i]<<" ";
    cout<<endl;
  }
  return 0;
}
