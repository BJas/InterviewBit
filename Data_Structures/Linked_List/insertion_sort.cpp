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
  void insertion_sort() {
    Node* temp = head;
    head = NULL;
    Node* next;
    while(temp) {
      next = temp->next;
      addToSort(temp);
      temp = next;
    }
  }
  void addToSort(Node* temp) {
    if(!head || temp->data<=head->data) {
      temp->next = head;
      head = temp;
    } else {
        Node* sortedNode = head;
        while(sortedNode->next && sortedNode->next->data<temp->data) {
          sortedNode = sortedNode->next;
        }
          temp->next = sortedNode->next;
          sortedNode->next = temp;
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
  ll.insertion_sort();
  ll.print();
  return 0;
}
