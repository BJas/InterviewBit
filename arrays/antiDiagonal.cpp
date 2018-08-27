#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin>>n;
  int a[n][n];
  vector< vector<int> > res((n-1)*2+1);
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
        cin>>a[i][j];
    }
  }
  int i=0, j=0, ix=0, jx=0, t=1, k=0;
  while(k<(n-1)*2+1) {
    i=ix;
    j=jx;
    res[k].resize(t);
    while(i<t && j>=0) {
      res[k].push_back(a[i][j]);
      i++;
      j--;
      // cout<<"i j"<<i<<" "<<j<<" "<<t<<endl;
    }
    jx++;
    if(jx == n) {
      jx = n-1;
      ix++;
    }
    t++;
    if(t>n || checked) {
      t -= 1;
      checked = true;
    }
    k++;
  }
  for(int i=0; i<(); i++) {
    for(int j=0; j<; j++) {
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
