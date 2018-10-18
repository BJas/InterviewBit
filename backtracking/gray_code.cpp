#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void getCombination(int n, vector<int> &result, int& index) {
  if(n==0) {
    result.push_back(index);
    return;
  }

  getCombination(n-1, result, index);
  index = index ^ (1<<(n-1));
  getCombination(n-1, result, index);
}
int main() {
  int n, num = 0;
  cin>>n;
  vector<int> result;
  getCombination(n, result, num);
  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
  return 0;
}
