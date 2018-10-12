#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void getSubset(vector<int>& a, vector<int>& subset, vector<vector<int> >& result, int start) {
  printf("Start %d\n", start);
  for(int i=start; i<a.size(); i++) {
    subset.push_back(a[i]);
    result.push_back(subset);
    printf("Subset %d: ", i);
    for(int j=0; j<subset.size(); j++)
      printf("%d ", subset[j]);
    printf("\n");
    getSubset(a, subset, result, i+1);
    printf("End\n");
    subset.pop_back();
  }
  printf("Return\n");
  return;
}
int main() {
  int n, x;
  scanf("%d\n", &n);
  vector<int> a;
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  vector<int> subset;
  vector<vector<int> > result;
  result.push_back(subset);
  getSubset(a, subset, result, 0);
  printf("List is: \n");
  for(int i=0; i<result.size(); i++) {
    printf("{");
    for(int j=0; j<result[i].size(); j++) {
      printf("%d ", result[i][j]);
    }
    printf("}\n");
  }
  return 0;
}
