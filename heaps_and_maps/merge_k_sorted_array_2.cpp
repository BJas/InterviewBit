#include<iostream>
#include<climits>
#include<vector>
using namespace std;
struct HeapNode {
  int element;
  int i;
  int j;
};
class HeapMin {
  HeapNode *harr;
  int heap_size;
  public:
  HeapMin(HeapNode arr[], int hsize);

  void Heapify(int );

  HeapNode getMin() { return harr[0]; }

  int left(int i) { return i*2+1; }

  int right(int i) { return i*2+2; }

  void replace(HeapNode x) {
    harr[0] = x;
    Heapify(0);
  }
};

void getSortedArray(vector<vector<int> > &arr, int k) {

  HeapNode *harr = new HeapNode[k];
  for(int i=0; i<k; i++) {
    harr[i].element = arr[i][0];
    harr[i].i = i;
    harr[i].j = 1;
  }

  HeapMin hp(harr, k);
  vector<int> output;

  int input_sz = arr[0].size();
  int ss = input_sz*k;

  while(ss>0) {
    HeapNode curr = hp.getMin();
    output.push_back(curr.element);
    if(curr.j<input_sz) {
      curr.element = arr[curr.i][curr.j];
      curr.j++;
    } else {
      curr.element = INT_MAX;
    }
    hp.replace(curr);
    ss--;
  }

  for(int i=0; i<output.size(); i++)
    cout<<output[i]<<" ";
}
  void swap(HeapNode *first, HeapNode *second) {
    HeapNode temp = *first;
    *first = *second;
    *second = temp;
  }

  void HeapMin::Heapify(int i) {
    int current = i;
    int l = left(i);
    int r = right(i);
    if(l<heap_size && harr[l].element<harr[current].element)
      current = l;
    if(r<heap_size && harr[r].element<harr[current].element)
      current = r;

    if(current != i) {
      swap(&harr[current], &harr[i]);
      Heapify(current);
    }
  }

  HeapMin::HeapMin(HeapNode arr[], int hsize) {
    harr = arr;
    heap_size = hsize;
    int i = (heap_size-1)/2;
    while (i>=0) {
      Heapify(i);
      i--;
    }
  }

int main() {
  int n, k, x;
  cin>>n>>k;
  vector<vector<int> > inputs;
  for(int i=0; i<k; i++) {
    vector<int> temp;
    for(int j=0; j<n; j++) {
      cin>>x;
      temp.push_back(x);
    }
    inputs.push_back(temp);
  }
  getSortedArray(inputs, k);
  return 0;
}
