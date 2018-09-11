#include<iostream>
using namespace std;
int validNumber(string A) {
  int i=0;
  while(A[i]==' ') { i++; }
  if(A[i] == '-' || A[i] == '+' || A[i] == '.') i++;
  if(A[i]<'0' || A[i]>'9') return 0;
  while(A[i]>='0' && A[i]<='9') { i++; }
  if(A[i] == '.' && (i +1== A.size() || A[i+1] == 'e')) return 0;
  if(A[i] == '.') { i++; }
  if((A[i]<'0' || A[i]>'9') && i!=A.size() && A[i] != 'e') return 0;
  while(A[i]>='0' && A[i]<='9') { i++; }
  if(A[i] == 'e') i++;
  if(A[i] == '-' || A[i] == '+') i++;
  while(A[i]>='0' && A[i]<='9') { i++; }
  while(A[i]==' ') { i++; }
  if(i==A.size()) return 1;

  return 0;
}
int main() {
  string number;
  cin>>number;
  int result = validNumber(number);
  cout<<result;
  return 0;
}
