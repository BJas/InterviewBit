#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* insert(Node* head, int x) {
  Node* temp = new Node();
  temp->data = x;
  temp->next = NULL;
  if(head==NULL) {
    head = temp;
  }
  else {
    Node* nodes = head;
    while(nodes->next!=NULL)
      nodes = nodes->next;
    nodes->next = temp;
  }
  return head;
}

void print(Node* head) {
    if(head==NULL) return;
    // print(head->next); recursively print
    printf("%d ", head->data);
    print(head->next); //iteratively print
}

int main() {
  Node* head;
  head = NULL;
  int n, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    head = insert(head, x);
  }
  printf("List is:\n");
  print(head);
  printf("\n");
  return 0;
}
