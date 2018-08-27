#include<iostream>
using namespace std;
int main() {
  int A;
  cin>>A;
  int start = 2;
    while(A>1) {
        if(A%start==0) {
            A/=start;
        } else {
            start++;
        }
    }
  return 0;
}
