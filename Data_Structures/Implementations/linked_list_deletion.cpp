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
  temp->next = head;
  return temp;
}

void print(Node* head) {
  printf("List is: ");
  while(head!=NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

Node* deleteAt(Node* head, int k) {
    Node* prev = head;
    if(k==1) {
      head = prev->next;
      delete prev;
      return head;
    }
    for(int i=0; i<k-2; i++)
        prev = prev->next;
    Node* curr = prev->next;
    prev->next = curr->next;
    delete curr;
    return head;
}

Node* deleteNumber(Node* head, int k) {
  Node* temp = head;
  Node* rem = head;
  Node* prev = NULL;
  while(temp!=NULL) {
    if(temp->data==k) {
      if(prev==NULL) {
        prev = temp->next;
      }
      else
        prev->next = temp->next;
      rem = temp;
      delete rem;
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
  int n, x, k;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    head = insert(head, x);
  }
  print(head);
  printf("\nDelete number: ");
  scanf("%d", &k);
  head = deleteNumber(head, k);
  print(head);
  return 0;
}
