#include<iostream>
#include<vector>
using namespace std;
void swap(int *first, int *second) {
  int temp = *first;
  *first = *second;
  *second = temp;
}
void getPermutation(vector<int> &subset, vector<vector<int> > &result, int l, int r) {
  if(l==r) {
    result.push_back(subset);
    return;
  }
  for(int i=l; i<=r; i++) {
    swap(&subset[l], &subset[i]);
    getPermutation(subset, result, l+1, r);
    swap(&subset[l], &subset[i]);
  }
}
int main() {
  int n, x;
  cin>>n;
  vector<int> subset;
  for(int i=0; i<n; i++) {
    cin>>x;
    subset.push_back(x);
  }
  vector<vector<int> > result;
  getPermutation(subset, result, 0, n-1);
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++) {
      cout<<result[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
