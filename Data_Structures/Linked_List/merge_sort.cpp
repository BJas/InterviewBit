#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
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
      temp->next = NULL;
      headNode->next = temp;
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
  Node* front() {
    return head;
  }
};
void partition(Node* temp, Node** front, Node** back) {
  Node* slow = temp;
  Node* fast = temp->next;
  while(fast) {
    fast = fast->next;
    if(fast) {
      slow = slow->next;
      fast = fast->next;
    }
  }
  *front = temp;
  *back = slow->next;
  slow->next = NULL;
}
Node* merge(Node* a, Node* b) {
  if(!a) return b;
  if(!b) return a;
  Node* result;
  if(a->data<=b->data) {
    result = a;
    result->next = merge(a->next, b);
  } else {
    result = b;
    result->next = merge(a, b->next);
  }
  return result;
}
void mergeSort(Node** head) {
  Node* temp = *head;
  Node* front;
  Node* back;
  if(!temp || !temp->next) {
    return;
  }
  partition(temp, &front, &back);
  mergeSort(&front);
  mergeSort(&back);

  *head = merge(front, back);

}
int main() {
  LinkedList ll;
  int n, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    ll.push(x);
  }
  ll.print();
  Node* head = ll.front();
  mergeSort(&head);
  Node* temp = head;
  printf("List is: \n");
  while(temp) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  return 0;
}
