#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node* prev;
};
struct LinkedList {
  Node* head;
  LinkedList() {
    head = NULL;
  }

  Node* GetNewNode(int data) {
      Node* temp = new Node();
      temp->data = data;
      temp->next = NULL;
      temp->prev = NULL;
      return temp;
  }

  void push(int data) {
    Node* newNode = GetNewNode(data);
    if(head == NULL) {
      head = newNode;
    } else {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
    }
  }

  void push_back(int data) {
    Node* newNode = GetNewNode(data);
    if(head == NULL) {
      head = newNode;
    } else {
      Node* temp = head;
      while(temp->next)
        temp = temp->next;
      temp->next = newNode;
      newNode->prev = temp;
    }
  }

  void removeAt(int pos) {
    Node* temp = head;
    if(pos == 1) {
      head = temp->next;
      head->prev = NULL;
      delete temp;
    } else {
      while(pos>1 && temp!=NULL) {
        temp = temp->next;
        pos--;
      }
      (temp->prev)->next = temp->next;
      if(temp->next)
        (temp->next)->prev = temp->prev;
      delete temp;
    }
  }

  void printReverse() {
    Node* temp = head;
    while(temp->next)
      temp = temp->next;
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->prev;
    }
  }

  void print() {
    printf("List is:\n");
    Node* temp = head;
    while(temp!=NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
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
  ll.printReverse();
  return 0;
}
