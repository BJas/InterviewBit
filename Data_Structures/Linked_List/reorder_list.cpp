#include<iostream>
#include<stdio.h>
#include<math.h>
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
  int getSize(Node* listNode) {
    int listSize = 0;

    while(listNode) {
      listNode = listNode->next;
      listSize++;
    }

    if(listSize%2==0)
      return listSize/2-1;

    return listSize/2;
  }

  Node* reverse(Node* curr) {
    Node* prev = NULL;
    Node* next;
    while(curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
}

  void reorder() {
    Node* temp = head;

    int listSize = getSize(temp);

    while(listSize>0) {
      temp = temp->next;
      listSize--;
    }
    Node* prev = reverse(temp);

    temp = head;
    Node* next;
    Node* nextCurr;
    while(temp && prev) {
      next = temp->next;
      nextCurr = prev->next;
      temp->next = prev;
      prev->next = next;
      temp = next;
      prev = nextCurr;
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
  ll.reorder();
  ll.print();
  return 0;
}
