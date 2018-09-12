#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void intersection(int A[], int B[], int n, int m) {
  vector<int> result;
  int j=0, i=0;
  while(i<n && j<m) {
    if(A[i] == B[j]) {
      result.push_back(A[i]);
      j++;
      i++;
    } else if(A[i] < B[j]) i++;
      else j++;
  }
  for(int i=0; i<result.size(); i++)
      cout<<result[i]<<" ";
}
int main() {
  int n, m;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  cin>>m;
  int b[m];
  for(int i=0; i<m; i++)
    cin>>b[i];
  intersection(a, b, n, m);
  return 0;
}
