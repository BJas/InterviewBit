#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
  int data;
  Node* next;
};
struct Queue {
  Node* head;
  Node* tail;
  int s;
  Queue() {
    head = NULL;
    tail = NULL;
    s = 0;
  }
  void push(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(!head && !tail) {
      head = tail = temp;
      return;
    }
    tail->next = temp;
    tail = temp;
    s++;
  }
  void pop() {
    if(!head) {
      printf("Underflow\n");
      return;
    }
    if(head == tail) {
      head = tail = NULL;
    } else {
      Node* temp = head;
      head = head->next;
      s--;
      delete temp;
    }
  }
  int front() {
    if(!head) {
      printf("No data\n");
      return 0;
    }
    return head->data;
  }
  int back() {
    if(!tail) {
      printf("No data\n");
      return 0;
    }
    return tail->data;
  }
  int size() {
    return s;
  }
  void show() {
    Node* temp = head;
      printf("List is:\n");
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
};
int main() {
  Queue q;
  q.push(2);
  q.push(3);
  q.push(4);
  q.show();
  q.pop();
  q.show();
  q.push(5);
  q.push(6);
  q.pop();
  q.show();
  printf("Front is: %d\n", q.front());
  printf("Back is: %d\n", q.back());
  return 0;
}
