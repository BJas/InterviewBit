#include<iostream>
using namespace std;
int reverseBits(int a) {
  unsigned int result = 0;
  for(int i=0; i<32; i++) {
      if((a&(1<<i))>>i == 1)
        result |= 1<<(31-i);
  }
  return result;
}
int main() {
  int a;
  cin>>a;
  unsigned int result = reverseBits(a);
  cout<<result;
  return 0;
}
