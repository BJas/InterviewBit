#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int getSum(vector<int> &v) {
  int result = 0;
  for(int i=0; i<v.size(); i++)
    result += v[i];
  return result;
}
void getCombinationSum(vector<int> &v, vector<int> &subset, vector<vector<int> > &result, map<vector<int>, bool> used, int i, int k) {
  int sum = getSum(subset);

  if(sum==k && !used[subset]) {
    result.push_back(subset);
    used[subset] = true;
    return;
  }
  if(i>=v.size() || sum>k)
    return;
  if(used.find(subset) == used.end()) {
    used[subset] = false;
  }
  subset.push_back(v[i]);
  getCombinationSum(v, subset, result, used, i, k);
  subset.pop_back();
  getCombinationSum(v, subset, result, used, i+1, k);
}
int main() {
  int n, x, k;
  scanf("%d", &n);
  vector<int> v;
  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    v.push_back(x);
  }
  scanf("%d", &k);
  vector<int> subset;
  vector<vector<int> > result;
  map<vector<int>, bool> used;
  sort(v.begin(), v.end());
  getCombinationSum(v, subset, result, used, 0, k);
  for(int i=0; i<result.size(); i++) {
    printf("{");
    for(int j=0; j<result[i].size(); j++) {
      printf("%d ", result[i][j]);
    }
    printf("}\n");
  }
  return 0;
}
