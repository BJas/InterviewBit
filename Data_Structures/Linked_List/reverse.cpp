#include<iostream>
using namespace std;
struct Node {
  int data;
  Node* next;
};
Node* insert(Node* head, int d) {
  Node* temp = new Node();
  temp->data = d;
  temp->next = head;
  return temp;
}
void print(Node* head) {
  printf("List is:\n");
  while(head!=NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}
Node* reverse(Node* head) {
  Node* curr = head;
  Node* next = head;
  Node* prev = NULL;
  while(curr!=NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
};
Node* reverseRecursively(Node* head, Node* prev) {
  if(prev->next==NULL) {
    head = prev;
    return head;
  }
  return reverseRecursively(head, prev->next);
  Node* curr = prev->next;
  curr->next = prev;
  prev->next = NULL;

}
int main() {
  Node* head;
  head = NULL;
  int n, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    head = insert(head, x);
  }
  print(head);
  head = reverseRecursively(head, head);
  print(head);
  return 0;
}
