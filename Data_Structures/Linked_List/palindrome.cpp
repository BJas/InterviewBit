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
    printf("List is:\n");
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
  int getSize(Node* temp) {
    int len = 0;
    while(temp) {
      temp=temp->next;
      len++;
    }
    if(len%2==0)
      return len/2-1;
    return len/2;
  }
  Node* reverse(Node* temp) {
    Node* prev = NULL;
    Node* next;
    while(temp) {
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }
    return prev;
  }
  int isPalindrome() {
    Node* temp = head;
    int size = getSize(temp);
    while(size>0) {
      temp=temp->next;
      size--;
    }
    Node* curr = reverse(temp);
    temp = head;
    while(temp && curr) {
      if(temp->data!=curr->data)
        return 0;
      temp=temp->next;
      curr=curr->next;
    }
    return 1;
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
  int res = ll.isPalindrome();
  printf("%d", res);
  return 0;
}
