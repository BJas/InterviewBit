#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n], maxLen=0;
  for(int i=0; i<n; i++)
    cin>>a[i];
  int ans = 0;
  for(int i=0; i<31; i++) {
    int cnt = 0;
    for(int j=0; j<n; j++) {
      if(a[j]&(1<<i)) {
        cnt++;
      }
    }
    ans += (cnt*(n-cnt)*2);
  }
  cout<<ans;
  return 0;
}
