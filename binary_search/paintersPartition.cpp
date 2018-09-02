#include<iostream>
#include<climits>
using namespace std;
bool isPossible(int a[], int m, int k, int mid) {
  int req = 1, result = 0;
  for(int i=0; i<m; i++) {
    if(a[i]>mid) return false;
    if(a[i]+result>mid) {
      result = a[i];
      req++;
      cout<<mid<<" "<<req<<endl;
      if(req>k)
        return false;
    } else {
      result += a[i];
    }
  }
  return true;
}
int main() {
  int n, t, m;
  cin>>n>>t>>m;
  int a[m], sum = 0;
  for(int i=0; i<m; i++) {
    cin>>a[i];
    sum += a[i];
  }
  long long left = 0, right = sum, result = INT_MAX;
  while(left<=right) {
    long long mid = left+(right-left)/2;
    if(isPossible(a, m, n, mid)) {
      result = min(result, mid);
      right = mid-1;
    } else {
      left= mid+1;
    }
  }
  cout<<(t*left)%10000003<<endl;
  return 0;
}
