#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
  int data;
  Node* next;
};
struct LinkedList {
  Node* head;
  LinkedList() {
    head = NULL;
  }
  void push_back(int data) {
    Node* temp = new Node();
    temp->data = data;
    if(!head) {
      temp->next = head;
      head = temp;
    } else {
      Node* headNode = head;
      while(headNode->next)
        headNode = headNode->next;
      headNode->next = temp;
      temp->next = NULL;
    }
  }

  void print() {
    Node* temp = head;
    printf("List is:\n");
    while(temp) {
      printf("%d ", temp->data);
      temp=temp->next;
    }
    printf("\n");
  }

  Node* first() {
    return head;
  }
};
void mergeSort(Node* first, Node* second) {
  Node* firstNode = first;
  Node* secondNode = second;
  Node* prev;
  Node* next;
  Node* secondNext;
  while(firstNode && secondNode) {
    printf("%d\n", firstNode->data);
    if( firstNode->next
        && firstNode->data<=secondNode->data
        && secondNode->data<=firstNode->next->data) {

      next = firstNode->next;
      secondNext = secondNode->next;
      firstNode->next = secondNode;
      secondNode->next = next;

      secondNode = secondNext;
      firstNode = firstNode->next;
    } else {
      prev = firstNode;
      firstNode = firstNode->next;
    }
  }
  while(secondNode) {
    prev->next = secondNode;
    prev = prev->next;
    secondNode = secondNode->next;
  }
}
int main() {
  LinkedList ll;
  LinkedList ll2;
  int n, m, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    ll.push_back(x);
  }
  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    scanf("%d", &x);
    ll2.push_back(x);
  }
  ll.print();
  ll2.print();
  Node* first = ll.first();
  Node* second = ll2.first();
  if(first->data<=second->data)
    mergeSort(first, second);
  if(first->data>second->data)
    mergeSort(second, first);
  ll2.print();
  return 0;
}
