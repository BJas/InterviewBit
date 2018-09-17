#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > sumZero(vector<int> A) {
  sort(A.begin(), A.end());
    vector< vector<int> > result;
    if(A.size()<3) return result;
    int x, i=0;
    while(i<A.size()) {
        int l = i+1, r = A.size()-1;
        x = A[i];
        while(l<r) {
            vector<int> temp;
            int lx = A[l], rx = A[r];
            if(x+lx+rx==0) {
                temp.push_back(x);
                temp.push_back(lx);
                temp.push_back(rx);
                result.push_back(temp);
                while(lx==A[l])
                    l++;
                while(rx==A[r])
                    r--;
            }
            else if(-(A[i]+A[l])<A[r])
                r--;
            else
                l++;
        }
        while(x==A[i])
            i++;
    }
    return result;
}
int main() {
  int n;
  cin>>n;
  vector<int>A(n);
  for(int i=0; i<n; i++)
    cin>>A[i];
  vector< vector<int> > result = sumZero(A);
  for(int i=0; i<result.size(); i++) {
    for(int j=0; j<result[i].size(); j++)
      cout<<result[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
