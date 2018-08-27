#include<iostream>
#include<vector>
using namespace std;
int main() {
  int A;
  cin>>A;
  int n = A*2-1;
    vector<vector <int> > result;
    int left = 0, right = n, top = 0, bottom = n;
    result.resize(n);
    for(int i=0; i<n; i++) {
      result[i].resize(n);
      for(int j=0; j<n; j++) {
          result[i].push_back(1);
      }
    }
    while(left<right) {
        for(int j=left; j<right; j++) {
            result[top][j] = A;
        }
        top++;
        for(int i=top; i<bottom; i++) {
            result[i][right-1] = A;
        }
        right--;
        if(left<right) {
            for(int j=right-1; j>=left; j--) {
                result[bottom-1][j] = A;
            }
            bottom--;
        }
        if(top<bottom) {
            for(int i=bottom-1; i>=top; i--) {
                result[i][left] = A;
            }
            left++;
        }

        A--;
    }
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
          cout<<result[i][j]<<" ";
      }
      cout<<endl;
    }
    return 0;
}
