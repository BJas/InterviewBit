#include<iostream>
#include<queue>
#include<climits>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
};
Node* getNewNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
Node* insert(int data, Node* root) {
  Node* current = getNewNode(data);
  if(!root) {
    root = current;
  } else if(data <= root->data) {
    root->left = insert(data, root->left);
  } else {
    root->right = insert(data, root->right);
  }
  return root;
}
// bool IsSubtreeLesser(Node* root, int data) {
//   cout<<"less"<<root->data<<endl;
//   if(!root) return true;
//   if(root->data <= data
//      && IsSubtreeLesser(root->left, data)
//      && IsSubtreeLesser(root->right, data))
//     return true;
//   return false;
// }
// bool IsSubtreeGreater(Node* root, int data) {
//   cout<<"great"<<root->data<<endl;
//   if(!root) return true;
//   if(root->data > data
//      && IsSubtreeGreater(root->left, data)
//      && IsSubtreeGreater(root->right, data))
//     return true;
//   return false;
// }
bool checkBST(Node* root, int minValue, int maxValue) {
  if(!root) return true;
  cout<<root->data<<endl;
  if(root->data > minValue
     && root->data < maxValue
     && checkBST(root->left, minValue, root->data)
     && checkBST(root->right, root->data, maxValue)) {
    return true;
  }
  else
    return false;
}
vector<int> arr;
bool checkInorder(Node* root, Node *&prev) {
  if(!root) return true;
  checkInorder(root->left, prev);
  if(prev && root->data <= prev->data)
    return false;
  arr.push_back(root->data);
  prev = root;
  checkInorder(root->right, prev);
  return true;
}
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(15, root);
  root = insert(7, root);
  root = insert(8, root);
  Node* prev = NULL;
  cout<<checkInorder(root, prev)<<endl;
  for(int i=0; i<arr.size(); i++)
    cout<<arr[i]<<" ";
  return 0;
}
