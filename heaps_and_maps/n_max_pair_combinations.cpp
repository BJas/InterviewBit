#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
int main() {
  int n, x, counter;
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

  printf("Give number K:\n");
  scanf("%d", &counter);

  sort(first.begin(), first.end());
  sort(second.end(), second.end());

  int firstIndex = n-1, secondIndex = n-1;
  int tempResult = first[firstIndex]+second[secondIndex];

  set<pair<int, int> > indexSet;
  indexSet.insert(make_pair(firstIndex, secondIndex));

  priority_queue<pair<int, pair<int, int> > > pq;
  pq.push(make_pair(tempResult, make_pair(firstIndex, secondIndex)));

  vector<int> output;

  for(int i=0; i<counter; i++) {
    pair<int, pair<int, int> > tempQueue = pq.top();
    pq.pop();
    output.push_back(tempQueue.first);
    firstIndex = tempQueue.second.first;
    secondIndex = tempQueue.second.second;

    pair<int, int> temp = make_pair(firstIndex-1, secondIndex);
    tempResult = first[firstIndex-1]+second[secondIndex];
    if(indexSet.find(temp) == indexSet.end()) {
      pq.push(make_pair(tempResult, temp));
      indexSet.insert(temp);
    }

   temp = make_pair(firstIndex, secondIndex-1);
   tempResult = first[firstIndex]+second[secondIndex-1];
   if(indexSet.find(temp) == indexSet.end()) {
      pq.push(make_pair(tempResult, temp));
      indexSet.insert(temp);
   }
  }
  for(int i=0; i<output.size(); i++)
    printf("%d ", output[i]);
  return 0;
}
