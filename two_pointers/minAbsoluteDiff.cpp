#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int minAbsolute(vector<int> &A, vector<int> &B, vector<int> &C) {
  int i=0, j=0, k=0, result = INT_MAX;
  while(i<A.size() && j<B.size() && k<C.size()) {
    int m = min(A[i], min(B[j], C[k])), n = max(A[i], max(B[j], C[k]));
    if(abs(n-m)<result)
      result = abs(n-m);
    if(m==A[i]) i++;
    else if(m==B[j]) j++;
    else k++;
  }
  return result;
}
int main() {
  int n;
  cin>>n;
  vector<int> A(n), B(n), C(n);
  for(int i=0; i<n; i++)
    cin>>A[i];
  for(int i=0; i<n; i++)
    cin>>B[i];
  for(int i=0; i<n; i++)
    cin>>C[i];
  int result = minAbsolute(A, B, C);
  cout<<result;
  return 0;
}
