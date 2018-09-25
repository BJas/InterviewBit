#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
  int data;
  Node* next;
};
int main() {
  Node* head = NULL;
  Node* head2 = NULL;
  Node* temp = head;
  Node* temp2 = head2;
  int k = 0, l = 0;
  while(temp!=NULL) {
    temp=temp->next;
    k++;
  }
  while(temp2!=NULL) {
    temp2=temp2->next;
    l++;
  }
  temp = head;
  temp2 = head2;
  while(k!=l) {
    if(k>l) {
      temp = temp->next;
      k--;
    }
    else {
      temp2 = temp2->next;
      l--;
    }
  }
  Node* result = NULL;
  while(temp!=NULL && temp2!=NULL) {
    if(temp==temp2) {
      result = temp;
    }
    temp = temp->next;
    temp2 = temp2->next;
  }

  return 0;
}
