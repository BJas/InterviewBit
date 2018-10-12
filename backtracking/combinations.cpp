#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void getCombination(int A, vector<vector<int> > &result, vector<int> &subset, int k, int i) {

  if(subset.size()==k) {
    result.push_back(subset);
    return;
  }
  if(i>A)
    return;
  subset.push_back(i);
  getCombination(A, result, subset, k, i+1);
  printf("pops %d\n", i);
  subset.pop_back();
  getCombination(A, result, subset, k, i+1);
}
int main() {
  int n, x, k;
  scanf("%d", &n);
  scanf("%d", &k);
  vector<int> subset;
  vector<vector<int> > result;
  getCombination(n, result, subset, k, 1);
  for(int i=0; i<result.size(); i++) {
    printf("{");
    for(int j=0; j<result[i].size(); j++) {
      printf("%d ", result[i][j]);
    }
    printf("}\n");
  }
  return 0;
}
