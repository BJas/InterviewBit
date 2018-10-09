#include<iostream>
using namespace std;
#define INT_MAX 101
struct Queue {
  int a[INT_MAX];
  int head;
  int tail;
  Queue() {
    head = INT_MAX/2;
    tail = INT_MAX/2;
  }
  void push(int x) {
    a[tail--] = x;
  }
  void pop() {
    if(head==tail) {
      cout<<"Overflow"<<endl;
      return;
    }
    head--;
  }
  int front() {
    if(head==tail)
      return -1;
    return a[head];
  }
  int back() {
    if(head==tail)
      return -1;
    return a[tail+1];
  }
  void show() {
    for(int i=tail+1; i<=head; i++) {
      cout<<a[i]<<" ";
    }
    cout<<endl;
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
  cout<<"Front is: "<<q.front()<<endl;
  cout<<"Back is: "<<q.back()<<endl;
  return 0;
}
