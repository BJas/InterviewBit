#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void getSubset(vector<int>& v, vector<int>& subset, vector<vector<int> >& result, int start) {
  result.push_back(subset);
  for(int i=start; i<v.size(); i++) {
    subset.push_back(v[i]);
    getSubset(v, subset, result, i+1);
    subset.pop_back();
  }
  return;
}
int main() {
  int n, x;
  vector<int> v;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  vector<int> subset;
  vector<vector<int> > result;
  getSubset(v, subset, result, 0);
  printf("List is:\n");
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  return 0;
}
