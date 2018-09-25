#include<iostream>
using namespace std;
struct Node {
  int data;
  Node* link;
};
Node* A;
void addNode(int d) {
  Node* temp = new Node();
  temp->data = d;
  temp->link = A;
  A = temp;
}
void printNode() {
  Node* temp = A;
  while(temp != NULL) {
    int d = temp->data;
    cout<<d<<" ";
    temp = temp->link;
  }
}
int main() {
  A = NULL;
  addNode(2);
  addNode(3);
  addNode(4);
  printNode();
  return 0;
}
