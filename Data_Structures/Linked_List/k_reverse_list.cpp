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
  Node* getNext(Node* temp, int k) {
    while(temp && k>0) {
      temp=temp->next;
      k--;
    }
    return temp;
  }
  Node* reverseK(Node* temp, int k) {
    Node* prev = NULL;
    Node* next;
    while(temp && k>0) {
      next=temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
      k--;
    }
    return prev;
  }
  Node* getCurrent(Node* temp) {
    while(temp->next)
      temp=temp->next;
    return temp;
  }
  void reverse(int k) {
    Node* temp = head;
    Node* prev = NULL;
    Node* curr;
    Node* next;
    while(temp) {
      next = getNext(temp, k);
      if(!prev) {
        prev = reverseK(temp, k);
        curr = getCurrent(prev);
        head = prev;
      }
      else {
        prev = reverseK(temp, k);
        curr->next = prev;
        curr = getCurrent(prev);
      }
      temp = next;
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
  ll.reverse(3);
  ll.print();
  return 0;
}
