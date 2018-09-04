#include<iostream>
using namespace std;
int strStr(string A, string B) {
  if(A.size()<B.size() || A.size() == 0 || B.size() == 0)
    return -1;
  int i=0;
  while(i<A.size()) {
    if(B[0] == A[i]) {
      bool isCheck = true;
      for(int p = 0; p < B.size(); p++) {
        if(A[p+i] != B[p]) {
          isCheck = false;
        }
      }
      if(isCheck)
        return i;
    }
    i++;
  }
  return -1;
}
int main() {
  string A, B;
  cin>>A>>B;
  int result = strStr(A, B);
  cout<<result;
}
