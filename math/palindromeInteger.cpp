#include<iostream>
#include<cmath>
using namespace std;
int main() {
  int A;
  cin>>A;
  if(A<0) cout<<0;
    int dig=0, temp=A;
    while(temp>0) {
        dig++;
        temp/=10;
    }
    int ind = 0, temp2=A;
    while(dig>ind) {
        int first = temp2%10;
        int second = (int)(A/pow(10,dig-1))%10;
        if(first!=second) {
          cout<<0;
        }
        temp2/=10;
        ind++;
        dig--;
    }
    cout<<1;
  return 0;
}
