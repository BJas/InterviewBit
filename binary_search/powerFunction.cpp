#include<iostream>
using namespace std;
int power(int d, int p, int r) {
  if(p == 0) return 1%r;
  if(d<0) d = abs(d+r);
  int count = d, ans = 1;
  while(p>0) {
    if(p%2 == 0) {
      count = (count*count)%r;
      p /= 2;
    } else {
      ans = (ans*count)%r;
      p--;
    }
  }
  return ans;
}
int main() {
  int d, p, r;
  cin>>d>>p>>r;
  int result = power(d, p, r);
  cout<<result;
  return 0;
}
