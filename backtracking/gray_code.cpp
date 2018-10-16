#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void getCombination(int n, vector<string> &result, char ch[], int index) {
  if(n==index) {
    result.push_back(ch);
    return;
  }

  for(int i=index; i<n; i++) {
    ch[index] = '0';
    getCombination(n, result, ch, i+1);
    ch[index] = '1';
  }
}
int main() {
  int n;
  cin>>n;
  vector<string> result;
  char ch[n+1];
  ch[n] = '\0';
  getCombination(n, result, ch, 0);
  sort(result.begin(), result.end());
  for(int i=0; i<result.size(); i++)
    cout<<result[i]<<" ";
  return 0;
}
