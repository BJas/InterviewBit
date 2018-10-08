#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX_SIZE 101
class Stack {
  private:
    int top;
    int A[MAX_SIZE];
  public:
    Stack() {
      top = -1;
    }
    void push(int value) {
      if(top == MAX_SIZE-1) {
        printf("Error: stack overflow\n");
        return;
      }
      top++;
      A[top] = value;
    }
    void pop() {
      if(top==-1) {
        printf("Error: No element to pop\n");
        return;
      }
      top--;
    }
    int front() {
      return A[top];
    }
    bool isEmpty() {
      if(top==-1)
        return true;
      return false;
    }
    void print() {
      for(int i=0; i<=top; i++) {
        printf("%d ", A[i]);
      }
      printf("\n");
    }
};
int main() {
  Stack st;
  st.pop();
  st.push(2);
  st.print();
  st.push(10);
  st.push(5);
  st.print();
  st.pop();
  st.print();
  return 0;
}
