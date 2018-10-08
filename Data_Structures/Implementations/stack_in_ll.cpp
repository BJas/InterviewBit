#include<iostream>
#include<stdio.h>
using namespace std;
struct Node {
  int data;
  Node* next;
};
class Stack {
  private:
    Node* head;
  public:
    Stack() {
      head = NULL;
    }
    void push(int x) {
      Node* temp = new Node();
      temp->data = x;
      temp->next = head;
      head = temp;
    }
    int top() {
      return head->data;
    }
    void pop() {
      if(!head) {
        printf("Nothing to pop\n");
      } else {
        Node* temp = head;
        head = temp->next;
        delete temp;
      }
    }
    void print() {
      Node* temp = head;
      while(temp) {
        printf("%d ", temp->data);
        temp=temp->next;
      }
      printf("\n");
    }
};
int main() {
  Stack st;
  st.push(2);
  st.push(3);
  st.print();
  st.push(4);
  st.push(5);
  st.print();
  st.pop();
  st.print();
  return 0;
}
