#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// Quick Sort Algorithm
// Time Complexity: O(nlogn) in average case
// Best case Time Complexity: O(nlogn)
// worst case Time Complexity: O(n^2) 


int Partition(vector < int >& vec, int l, int r){
    int pivot = vec[r], i = l; // pivot is the last element in the subarray
    for(int j = l; j < r; j++){ // j is the current element
        if(vec[j] <= pivot) // if the current element is less than the pivot
            swap(vec[i++], vec[j]); // swap the current element with the first element in the right subarray
    }
    swap(vec[i], vec[r]); // swap the pivot with the first element in the right subarray
    return i; // return the index of the pivot
}

void Quick_Sort(vector < int >& vec, int l, int r){
  if(l >= r) return; // base case (the subarray has one or zero elements) the subarray is already sorted
  int pivot = Partition(vec, l, r); // partition the subarray
  Quick_Sort(vec, l, pivot - 1); // sort the left subarray
  Quick_Sort(vec, pivot + 1, r); // sort the right subarray
}

// implement using other idea

void quick_sort(vector < int >& vec){

  // (the subarray has one or zero elements) the subarray is already sorted
  if(sz(vec) <= 1) return; // base case 
  int pivot = vec[0];
  vector < int > left, right;
  for(int i = 1; i < sz(vec); i++){
      // if the current element is less than the pivot, add it to the left subarray
      if(vec[i] < pivot) left.push_back(vec[i]); 
      // if the current element is greater than the pivot, add it to the right subarray
      else right.push_back(vec[i]);
  }

  // the all elements in the left subarray are less than the pivot
  // the all elements in the right subarray are greater than the pivot

  // recursive calls
  quick_sort(left); // sort the left subarray
  quick_sort(right); // sort the right subarray

  vec.clear(); // clear the vector to add the sorted elements

  // merge the left subarray, the pivot, and the right subarray
  for(auto x: left) vec.push_back(x); 
  vec.push_back(pivot);
  for(auto x: right) vec.push_back(x);

}


int main(){
  
  int n; 
  cin >> n;
  vector < int > vec(n);
  for (auto& i: vec) cin >> i;
  quick_sort(vec);
  for (auto i: vec) cout << i << " ";

}
