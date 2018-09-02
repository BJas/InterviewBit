#include<iostream>
#include<string>
using namespace std;
int main() {
  string A;
  cin>>A;
  int len = A.size(), i=0, j=A.size()-1;
  while(i<j) {
    if(isalnum(A[i]) && isalnum(A[j])){
      if(tolower(A[i]) != tolower(A[j])){
        cout<<0;
        break;
      }
      i++;
      j--;
    }
    if(!isalnum(A[i]))
        i++;
     if(!isalnum(A[j]))
        j--;
  }

  cout<<1;
  return 0;
}
