#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* insert(Node* head, int n) {
  Node* temp = new Node();
  temp->data = n;
  temp->next = head;
  return temp;
}

void print(Node* head) {
  printf("List is\n");
  while(head!=NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

Node* deleteNumber(Node* head, int k) {
  Node* temp = head;
  Node* prev = NULL;
  Node* toRemove;
  while(temp!=NULL) {
    if(temp->data == k) {
      if(prev == NULL)
        prev = temp->next;
      else
        prev->next = temp->next;
      toRemove = temp;
      delete toRemove;
    }
    else
      prev = temp;
    temp = temp->next;
  }
  return head;
}

int main() {
  Node* head;
  head = NULL;
  head = insert(head, 2);
  head = insert(head, 4);
  head = insert(head, 6);
  head = insert(head, 8);
  print(head);
  int k;
  printf("Number to delete: \n");
  scanf("%d", &k);
  head = deleteNumber(head, k);
  print(head);
  return 0;
}
