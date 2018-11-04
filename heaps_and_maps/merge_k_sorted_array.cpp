#include<iostream>
#include<vector>
using namespace std;
struct MinHeapNode {
  int element;
  int i;
  int j;
};

void swap(MinHeapNode *x, MinHeapNode *y);

class MinHeap
{
  MinHeapNode *harr;
  int heap_size;

public:
  MinHeap(MinHeapNode a[], int size);

  void MinHeapify(int );

  int left(int i) { return 2*i + 1; }

  int right(int i) { return 2*i + 2; }

  MinHeapNode getMin() { return harr[0]; }

  void replaceMin(MinHeapNode curr) { harr[0] = curr; MinHeapify(0); }
};

void sortArrays(vector<vector<int> > &arr, int k) {
  MinHeapNode *harr = new MinHeapNode[k];
  for(int i=0; i<k; i++) {
    harr[i].element = arr[i][0];
    harr[i].i = i;
    harr[i].j = 1;
  }

  MinHeap hp(harr, k);

  vector<int> output;

  for(int t=0; t<arr[0].size()*k; t++) {
    MinHeapNode min_number = hp.getMin();
    output.push_back(min_number.element);
    if(min_number.j<arr[min_number.i].size()) {
      min_number.element = arr[min_number.i][min_number.j];
      min_number.j +=1 ;
    } else {
      min_number.element = INT_MAX;
    }

    hp.replaceMin(min_number);
  }
  for(int i=0; i<output.size(); i++)
    cout<<output[i]<<" ";
}

void swap(MinHeapNode *x, MinHeapNode *y) {
  MinHeapNode temp = *x;
  *x = *y;
  *y = temp;
}

MinHeap::MinHeap(MinHeapNode a[], int size) {
  heap_size = size;
  harr = a;
  int i = (heap_size-1)/2;
  while(i>=0) {
    MinHeapify(i);
    i--;
  }
}

void MinHeap::MinHeapify(int i) {
  int curr = i;
  int l = left(i);
  int r = right(i);

  if(l<heap_size && harr[l].element<harr[curr].element)
    curr = l;

  if(r<heap_size && harr[r].element<harr[curr].element)
    curr = r;

  if(curr != i) {
    swap(&harr[i], &harr[curr]);
    MinHeapify(curr);
  }
}

int main() {
  vector<vector<int> > inputs;
  int n, k, x;
  cin>>n>>k;
  for(int i=0; i<k; i++) {
    vector<int> temp;
    for(int j=0; j<n; j++) {
      cin>>x;
      temp.push_back(x);
    }
    inputs.push_back(temp);
  }

  sortArrays(inputs, inputs.size());
  return 0;
}
