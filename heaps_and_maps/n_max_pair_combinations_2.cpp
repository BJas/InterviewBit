#include<stdio.h>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int main() {
  int n, x;
  scanf("%d", &n);
  vector<int> first, second;

  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    first.push_back(x);
  }

  for(int i=0; i<n; i++) {
    scanf("%d", &x);
    second.push_back(x);
  }

  sort(first.begin(), first.end());
  sort(second.begin(), second.end());

  set<pair<int, int> > indexSet;
  priority_queue<pair<int, pair<int, int> > > sq;

  pair<int, int> tempPair = make_pair(n-1, n-1);
  indexSet.insert(make_pair(n-1, n-1));
  sq.push(make_pair(first[n-1]+second[n-1], make_pair(n-1, n-1)));

  vector<int> output;

  for(int i=0; i<n; i++) {
    pair<int, pair<int, int> > currentQueue = sq.top();
    sq.pop();

    output.push_back(currentQueue.first);

    int firstIndex = currentQueue.second.first;
    int secondIndex = currentQueue.second.second;

    tempPair = make_pair(firstIndex-1, secondIndex);

    if(indexSet.find(make_pair(firstIndex-1, secondIndex)) == indexSet.end()) {
      sq.push(make_pair(first[firstIndex-1] + second[secondIndex], make_pair(firstIndex-1, secondIndex)));
      indexSet.insert(make_pair(firstIndex-1, secondIndex));
    }

    tempPair = make_pair(firstIndex, secondIndex-1);

    if(indexSet.find(make_pair(firstIndex, secondIndex-1)) == indexSet.end()) {
      sq.push(make_pair(first[firstIndex] + second[secondIndex-1], make_pair(firstIndex, secondIndex-1)));
      indexSet.insert(make_pair(firstIndex, secondIndex-1));
    }
  }
  for(int i=0; i<output.size(); i++) {
    printf("%d ", output[i]);
  }
  return 0;
}
