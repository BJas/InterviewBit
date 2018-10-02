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
  void part_sort(int k) {
    Node* temp = head;
    Node* next;
    Node* prev = NULL;
    Node* curr = NULL;
    Node* currHead = NULL;
    while(temp) {
      next = temp->next;
      temp->next = NULL;
      if(temp->data<k) {

        if(!prev) head = temp;
        else prev->next = temp;

        prev = temp;

      } else {

        if(!curr) currHead = temp;
        else  curr->next = temp;

        curr = temp;
      }
      temp = next;
    }
    if(prev) {
      prev->next = currHead;
    }
  }


  void print() {
    Node* temp = head;
    printf("List is\n");
    while(temp) {
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
    ll.push(x);
  }
  int k;
  scanf("%d", &k);
  ll.part_sort(k);
  ll.print();
  return 0;
}
