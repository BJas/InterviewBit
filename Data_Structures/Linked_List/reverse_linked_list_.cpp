#include<iostream>
#include<stdio.h>
using namespace std;
struct LinkNode {
  int data;
  LinkNode* next;
};
struct LinkedList {
  LinkNode* head;
  LinkedList() {
    head = NULL;
  }
  void push_back(int data) {
    LinkNode* temp = new LinkNode();
    temp->data = data;
    if(head==NULL) {
      temp->next = head;
      head = temp;
    } else {
      LinkNode* headNode = head;
      while(headNode->next) {
        headNode = headNode->next;
      }
      headNode->next = temp;
      temp->next = NULL;
    }
  }
  void print() {
    LinkNode* temp = head;
    printf("List is:\n");
    while(temp) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
  void reverse(int l, int r) {
    LinkNode* start = head;
    LinkNode* middle;
    int left = l, diff = 0;
    if(left>1) {
      left -= 2;
      while(left>0) {
        start = start->next;
        left--;
      }
      middle = start->next;
    }
    else {
      middle = start;
    }

    LinkNode* temp = middle;
    LinkNode* curr;
    LinkNode* prev = NULL;
    while(diff<=r-l) {
      curr = middle->next;
      middle->next = prev;
      prev = middle;
      middle = curr;
      diff++;
    }
    if(l==1)
      head = prev;
    else
      start->next = prev;
    temp->next = middle;

  }
};
int main() {
  LinkedList ll;
  int n, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
      scanf("%d", &x);
      ll.push_back(x);
  }
  ll.print();
  ll.reverse(2, 5);
  ll.print();
  return 0;
}
