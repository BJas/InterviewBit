#include<iostream>
using namespace std;
int numberOf1Bits(int a) {
  int cnt = 0;
  while(a!=0) {
    a = a&(a-1);
    cnt++;
  }
  return cnt;
}
int main() {
  int a;
  cin>>a;
  int result = numberOf1Bits(a);
  cout<<result;
  return 0;
}
