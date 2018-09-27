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
  void loopCycle() {
    Node* slow = head;
    Node* fast = head;
    bool isLoop = false;
    while(fast && slow) {
      if(fast==slow)
        isLoop = true;
      slow = slow->next;
      fast = fast->next->next;
    }
    if(isLoop) {
      Node* temp = head;
      while(temp!=slow) {
        slow = slow->next;
        temp = temp->next;
      }
    }
    printf("%d\n", curr->data);
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
  ll.loopCycle();
}
