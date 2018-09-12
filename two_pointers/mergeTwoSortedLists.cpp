#include<iostream>
using namespace std;
void mergeSort(int A[], int B[], int n, int m) {
  int i=0, j=0;
    while(A[0]>B[j]) {
        A.insert(A.begin(), B[j]);
        j++;
    }
    while(i<n+m && j<m) {
        if(A[i]<=B[j] && B[j]<=A[i+1] && i != n+j-1) {
            A.insert(A.begin()+i+1, B[j]);
            j++;
        }
        i++;
    }
    while(j<m) {
        A.insert(A.begin()+n+j, B[j]);
        j++;
    }
  for(int i=0; i<A.size(); i++)
    cout<<A[i];
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
  mergeSort(a, b, n, m);
  return 0;
}
