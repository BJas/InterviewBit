#include<iostream>
using namespace std;
int search(int A[][3], int n, int x) {
  int left = 0, right = n-1;
  while(left<=right) {
    int mid = left+(right-left)/2;
    if(A[mid][0]==x) return mid;
    if(A[mid][0]>x && A[(mid-1+n)%n][0]<=x) return mid-1;
    else if(A[mid][0]>x)
      right = mid-1;
    else
      left = mid+1;
  }
  return -1;
}
int binarySearch(int A[][3], int m, int x, int i) {
  int left = 0, right = m-1;
  while(left<=right) {
    int mid = left+(right-left)/2;
    if(A[i][mid] == x) return 1;
    else if(A[i][mid]>x)
      right = mid-1;
    else
      left = mid+1;
  }
  return 0;
}
int main() {
  int n;
  cin>>n;
  int a[n][3];
  for(int i=0; i<n; i++)
    for(int j=0; j<3; j++)
      cin>>a[i][j];
  int x;
  cin>>x;
  int row = search(a, n, x);
  int result = binarySearch(a, 3, x, row);
  cout<<row<<" "<<result<<endl;
  return 0;
}
