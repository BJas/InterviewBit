#include<iostream>
using namespace std;
struct Interval {
  int low, high;
};
struct ITNode {
  Interval* i;
  int max;
  ITNode* left;
  ITNode* right;
};

ITNode* getNode(Interval i) {
  ITNode* temp = new ITNode;
  temp->i = new Interval(i);
  temp->max = i.high;
  temp->left = temp->right = NULL;
  return temp;
}

ITNode* insert(ITNode* root, Interval i) {
  ITNode* current = getNode(i);
  if(!root) {
    return current;
  }

  int l = root->i->low;

  if(i.low < l) {
    root->left = insert(root->left, i);
  } else {
    root->right = insert(root->right, i);
  }

  if(root->max < i.high) {
    root->max = i.high;
  }

  return root;
}
void traverse(ITNode* root) {
  if(!root) return;
  traverse(root->left);
  cout<<"["<<root->i->low<<", "<<root->i->high<<"] "<<"max: "<<root->max<<endl;
  traverse(root->right);
}
Interval* search(ITNode* root, Interval i) {
  if(!root) return NULL;

  if(i.low <= root->i->high && root->i->low <= i.high)
    return root->i;

  if(root->left || root->left->max >= i.low)
    return search(root->left, i);

  return search(root->right, i);
}
int main() {
  Interval arr[] = {
    {15, 20}, {10 ,30}, {17, 19}, {5, 20},
    {12, 15}, {30, 40}
  };
  ITNode* root = NULL;
  int n = sizeof(arr) / sizeof(arr[0]);
  for(int i=0; i<n; i++) {
    root = insert(root, arr[i]);
  }

  traverse(root);
  Interval x = {6, 7};
  Interval* result = search(root, x);
  cout<<result->low<<" "<<result->high<<endl;


  return 0;
}
