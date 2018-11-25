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
class BSTIterator {
private:
  stack<Node*> st;
public:
  BSTIterator(Node* root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

  bool hasNext() {
    return !st.empty();
  }

  int next() {
    Node* current = st.top();
    int res = current->data;
    if(current->right) {
      current = current->right;
      while(current) {
        st.push(current);
        current = current->left;
      }
    }
    return res;
  }
};
int main() {
  Node* root = NULL;
  root = insert(10, root);
  root = insert(12, root);
  root = insert(15, root);
  root = insert(7, root);
  root = insert(8, root);
  BSTIterator* b = new BSTIterator(root);
  while(b->hasNext())
    cout<<b->next()<<endl;
  return 0;
}
