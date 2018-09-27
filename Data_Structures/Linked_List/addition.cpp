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
  Node* first() {
    return head;
  }
};
void addition(Node* first, Node* second) {
  Node* result = NULL;
  Node* prev;
  int remains = 0;
  while(first && second) {
    Node* temp = new Node();
    if(first && second) {
        temp->data = (first->data+second->data + remains)%10;
        remains = (first->data+second->data + remains)/10;
    } else if(first) {
        temp->data = (first->data + remains)%10;
        remains = (first->data + remains)/10;
    } else {
        temp->data = (second->data + remains)%10;
        remains = (second->data + remains)/10;
    }
    if(!result) {
      temp->next = result;
      result = temp;
    } else {
      prev->next = temp;
    }
    prev = temp;
    if(first)
        first = first->next;
    if(second)
        second = second->next;
  }
if(remains) {
    Node* temp = new Node();
    temp->data = remains;
    temp->next = NULL;
    prev->next = temp;
  }
  Node* res = result;
  printf("List is:\n");
  while(res) {
    printf("%d ", res->data);
    res = res->next;
  }
  printf("\n");
}
int main() {
  LinkedList ll;
  LinkedList ll2;
  int n, x, m;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    ll.push(x);
  }

  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    scanf("%d", &x);
    ll2.push(x);
  }
  ll.print();
  ll2.print();
  addition(ll.first(), ll2.first());
  return 0;
}
