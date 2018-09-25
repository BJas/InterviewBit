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
    printf("List is: \n");
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }

  void rotate(int k) {
    Node* temp = head;
    int len = 0;

    while(temp) {
      temp = temp->next;
      len++;
    }

    temp = head;
    k %= len;
    int revlen = len-2-k;

    while(revlen>=0) {
      temp = temp->next;
      revlen--;
    }

    Node* curr = temp->next;
    Node* prev = curr;
    temp->next = NULL;

    while(curr->next)
      curr = curr->next;
      
    curr->next = head;
    head = prev;
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
  int k;
  scanf("%d", &k);
  ll.rotate(k);
  ll.print();
  return 0;
}
