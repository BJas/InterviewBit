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
      while(headNode->next) {
        headNode = headNode->next;
      }
      headNode->next = temp;
      temp->next = NULL;
    }
  }

  void print() {
    Node* temp = head;
    printf("List is: \n");
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }

  void removeDuplicate() {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    while(curr!=NULL) {
      next = curr->next;
      if(prev!=NULL && prev->data == curr->data) {
        prev->next = curr->next;
        delete curr;
      }
      else
        prev = curr;
      curr = next;
    }
  }

  void removeFullDuplicate() {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    while(curr) {
      next = curr->next;
      if(next && curr->data==next->data) {
        while(next && curr->data==next->data) {
          curr->next = next->next;
          delete next;
          next = curr->next;
        }
        if(prev)
          prev->next = next;
        else
          head = next;
        delete curr;
      }
      else {
        prev = curr;
      }
      curr = next;
    }
  }
};
int main() {
  LinkedList ll;
  int n, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    ll.push_back(x);
  }
  ll.print();
  ll.removeFullDuplicate();
  ll.print();
  return 0;
}
