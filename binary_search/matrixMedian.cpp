#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int findMedian(int A[][3], int n) {
  int r=n,c=3;
    int req=(r*c+1)/2;
    int minm=INT_MAX,maxm=INT_MIN;
    for(int i=0;i<r;i++){
        minm=min(minm,A[i][0]);
        maxm=max(maxm,A[i][c-1]);
    }
    while(minm<maxm){
        int mid=minm+(maxm-minm)/2;
        int place=0;
        for(int i=0;i<r;i++)
         place+=upper_bound(A[i][0],A[i][c-1],mid)-A[i][c-1];

        if(place<req) minm=mid+1;
        else maxm=mid;
    }
    return minm;
}
int main() {
  int n;
  cin>>n;
  int a[n][3];
  for(int i=0; i<n; i++)
    for(int j=0; j<3; j++)
      cin>>a[i][j];
  int result = findMedian(a, n);
  cout<<result;
  return 0;
}
