#include<iostream>
#include<queue>
#include<algorithm>
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
void traverseZigzag(Node* root) {
  queue<pair<Node*, int> > q;
  vector<vector<int> > result;
  vector<int> temp;
  q.push(make_pair(root, 0));
  int level = 0;
  while(!q.empty()) {
    pair<Node*, int> current = q.front();
    q.pop();
    Node* currentNode = current.first;
    if(level!=current.second) {
      if(level % 2 == 1) {
          reverse(temp.begin(), temp.end());
      }
      result.push_back(temp);
      temp.clear();
      level++;
    }
    temp.push_back(currentNode->data);
    if(currentNode->left) q.push(make_pair(currentNode->left, current.second + 1));
    if(currentNode->right) q.push(make_pair(currentNode->right, current.second + 1));
  }
  if(level % 2 == 1) {
      reverse(temp.begin(), temp.end());
  }
  result.push_back(temp);
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++) {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main() {
  Node* root = NULL;
  root = insert(15, root);
  root = insert(10, root);
  root = insert(17, root);
  root = insert(20, root);
  root = insert(6, root);
  traverseZigzag(root);
  return 0;
}
