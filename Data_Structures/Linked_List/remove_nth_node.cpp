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

  void push_back(int data) {
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
      temp=temp->next;
    }
    printf("\n");
  }

  void deleteNode(int pos) {
    Node* temp = head;
    int len = 0;
    while(temp) {
      len++;
      temp = temp->next;
    }
    len = len - pos + 1;
    temp = head;
    if(len==1) {
      head = temp->next;
      delete temp;
    } else {
      len -= 2;
      while(len>0) {
        temp = temp->next;
        len--;
      }
      Node* curr = temp->next;
      temp->next = curr->next;
      delete curr;
    }
  }
};
int main() {
  LinkedList ll;
  int n, x, k;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    ll.push_back(x);
  }
  ll.print();
  scanf("%d", &k);
  ll.deleteNode(k);
  ll.print();
  return 0;
}
