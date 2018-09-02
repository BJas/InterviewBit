#include<iostream>
using namespace std;
int countOccurance(int A[], int n, int B, bool isFirst) {
  int left = 0, right = n-1, count = -1;
  while(left<=right) {
    int mid = left+(right-left)/2;
    if(A[mid] == B) {
      count = mid;
      if(isFirst)
        right = mid-1;
      else
        left = mid+1;
    } else if(A[mid]>B)
        right = mid-1;
      else
        left = mid+1;
  }
  return count;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int x;
  cin>>x;
  int first = countOccurance(a, n, x, true);
  int last =  countOccurance(a, n, x, false);
  if(first == -1)
    cout<<0;
  else
    cout<<last-first+1;
  return 0;
}
