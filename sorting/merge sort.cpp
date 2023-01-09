#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// best case: O(nlogn)
// worst case: O(nlogn)
// average case: O(nlogn)
// space complexity: O(n)
// time complexity: O(nlogn)


void merge(vector < int > &vec, int l, int m, int r){
  int n1 = m - l + 1; // size of the left half
  int n2 = r - m; // size of the right half
  vector < int > L(n1), R(n2); // left and right half of the array
  for (int i = 0; i < n1; i++) L[i] = vec[l + i]; // copy the left half
  for (int i = 0; i < n2; i++) R[i] = vec[m + 1 + i]; // copy the right half
  int i = 0, j = 0, k = l; // i for left half, j for right half, k for the original array
  while (i < n1 && j < n2){ // merge the two halves 
    if (L[i] <= R[j]) vec[k++] = L[i++]; // if the left half is smaller than the right half, put the left half in the original array
    else vec[k++] = R[j++]; // else put the right half in the original array
  }
  // if there are any elements left in the left half or the right half, put them in the original array
  while (i < n1) vec[k++] = L[i++]; 
  while (j < n2) vec[k++] = R[j++]; 
}

void merge_sort(vector < int > &vec, int l, int r){
  if (l < r){ // base case
    // ((l + r) / 2) = (l + (r - l) / 2)
    int m = (l + r) / 2; // mid point of the array 
    merge_sort(vec, l, m); // sort the left half
    merge_sort(vec, m + 1, r); // sort the right half
    merge(vec, l, m, r); // merge the two halves
  }
}

int main(){
  
  int n;
  cin >> n;
  vector < int > vec(n);
  for (auto& i: vec) cin >> i;
  merge_sort(vec, 0, n - 1);
  for (auto i: vec) cout << i << " ";

}