#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
string trim(string A){
    int m=A.length();
    string temp="";
    int i=0;
    while(i<m && A[i]=='0') i++;
    if(i==m)
        temp="0";
    else {
        for(;i<m;i++)
            temp+=A[i];
    }
    return temp;
}
int compareVersion(string A, string B) {
  int i=0, j=0;
  string first="", second="";
  A += '.';
  B += '.';
  while(i<A.size() || j<B.size()) {
    if((A[i]=='.' && B[j]=='.') || (i==A.size() && B[j]=='.') || (j==B.size() && A[i]=='.')) {
      first = trim(first);
      second = trim(second);
      if(first>second)
        return 1;
      else if(first<second)
        return -1;
      else {
        first = "";
        second = "";
        if(i!=A.size())i++;
        if(j!=B.size())j++;
      }
    } else if(A[i]!='.' && i<A.size()) {
      first += A[i];
      i++;
    } else if(B[j]!='.' && j<B.size()) {
      second += B[j];
      j++;
    }
  }
  return 0;
}
int main() {
  string A, B;
  cin>>A>>B;
  int result = compareVersion(A, B);
  cout<<result;
  return 0;
}
