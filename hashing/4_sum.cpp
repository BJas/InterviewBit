#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
void getSum(vector<int> &a, vector<vector<int> > &result, int k) {
  map<int, pair<int, int> > m;
  for(int i=0; i<a.size()-3; i++) {
    if(i>0 && a[i]==a[i-1])
      continue;
    for(int j=i+1; j<a.size()-2; j++) {
        if(j>i+1 && a[j]==a[j-1])
          continue;
        int l = j+1, r = a.size()-1, sum;
        while(l<r) {
          sum = a[i] + a[j] + a[l] + a[r];
          if(sum==k) {
            vector<int> temp;
            temp.push_back(a[i]);
            temp.push_back(a[j]);
            temp.push_back(a[l]);
            temp.push_back(a[r]);
            result.push_back(temp);
            l++;
            while(l<r && a[l]==a[l-1])
              l++;
          }
          else if(sum<k)
            l++;
          else
            r--;
        }
    }
  }
}
int main() {
  int n, x, k;
  cin>>n;
  vector<int> arr;
  for(int i=0; i<n; i++) {
    cin>>x;
    arr.push_back(x);
  }
  cin>>k;
  vector<vector<int> > result;
  sort(arr.begin(), arr.end());
  getSum(arr, result, k);
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++)
      cout<<result[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
