#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;
void maxConsec(int A[], int n) {
  int minVal = A[0], maxVal = A[0];
  for(int i=1; i<n; i++) {
    minVal = min(minVal, A[i]);
    maxVal = max(maxVal, A[i]);
  }

  float delta = (float)(maxVal-minVal)/(float)(n-1);
  vector<int> minBucket(n-1, INT_MAX);
  vector<int> maxBucket(n-1, -1);
  for(int i=0; i<n; i++) {
    if(minVal == A[i] || maxVal == A[i]) continue;
    int index = (float)((A[i]-minVal)/delta);
    cout<<"index: "<<index<<endl;
    cout<<"delta: "<<delta<<endl;
    if(maxBucket[index] == -1)
      maxBucket[index] = A[i];
    else
      maxBucket[index] = max(maxBucket[index], A[i]);
    if(minBucket[index] == INT_MAX)
      minBucket[index] = A[i];
    else
      minBucket[index] = min(minBucket[index], A[i]);
  }
  int maxx = 0;
  for(int i=0; i<n-1; i++) {
    if(minBucket[i] == INT_MAX) continue;
    maxx = max(maxx, minBucket[i]-minVal);
    minVal = maxBucket[i];
  }
  maxx = max(maxx,maxVal-minVal);
  cout<<maxx;
}
int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++) {
    cin>>a[i];
  }
  maxConsec(a, n);
  return 0;
}
