#include<iostream>
#include<vector>
using namespace std;
int main() {
  string A;
  int B;
  cin>>A>>B;
  vector<int> res;
    int start = 1, end = B;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == 'I') {
            res.push_back(start);
            start++;
        } else {
            res.push_back(end);
            end--;
        }
    }
    if(A[A.size()-1] == 'I') {
        res.push_back(start);
        start++;
    } else {
        res.push_back(end);
        end--;
    }
  for(int i=0; i<res.size(); i++) {
    cout<<res[i]<<" ";
  }
  return 0;
}
