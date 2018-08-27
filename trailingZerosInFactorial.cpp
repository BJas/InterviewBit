#include<iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int counter = 0;
  while(n>0) {
    counter += (n/5);
    n /= 5;
  }
  cout<<counter;
  return 0;
}
