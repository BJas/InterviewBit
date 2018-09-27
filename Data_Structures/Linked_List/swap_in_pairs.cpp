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
  void push(int data) {
    Node* temp = new Node();
    temp->data = data;
    if(!head) {
      temp->next = head;
      head = temp;
    } else {
      Node* headNode = head;
      while(headNode->next) {
        headNode = headNode->next;
      }
      headNode->next = temp;
      temp->next = NULL;
    }
  }
  void print() {
    Node* temp = head;
    printf("List is:\n");
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
  Node* swap(Node* prev, Node* curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev->next = next;
    return curr;
  }
  void swapNodes() {
    Node* temp = head;
    Node* next;
    Node* prev = NULL;
    while(temp && temp->next) {
      if(temp==head)
        head = temp->next;
      next = swap(temp, temp->next);
      if(prev)
        prev->next = next;
      prev = next->next;
      temp = next->next->next;
    }
  }
};
int main() {
  LinkedList ll;
  int n, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    ll.push(x);
  }
  ll.print();
  ll.swapNodes();
  ll.print();
  return 0;
}
