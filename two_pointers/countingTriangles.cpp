#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int checkToTriangle(vector<int> A) {
  sort(A.begin(), A.end());
  int cnt = 0;
  for(int i=0; i<A.size()-2; i++) {
    if(A[i]<=0) continue;
    int k = i+2;
    for(int j=i+1; j<A.size(); j++) {
      while(k<A.size() && A[i]+A[j]>A[k]) {
        k++;
        cnt+=k-j-1;
      }
    }

  }
  return cnt;
}
int main() {
  int n;
  cin>>n;
  vector<int>A(n);
  for(int i=0; i<n; i++)
    cin>>A[i];
  int result = checkToTriangle(A);
  cout<<result;
  return 0;
}
