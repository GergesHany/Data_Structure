#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// best case: O(n) // when the array is already sorted
// worst case: O(n^2) // when the array is sorted in descending order
// average case: O(n^2) // when the array is sorted in random order

void insertion_sort(vector < int >& vec){
   for (int i = 1; i < sz(vec); i++){
      int j = i - 1; // j is the index of the last element in the sorted part
      int key = vec[i]; // key is the element to be inserted
      while (j >= 0 && vec[j] > key){
         vec[j + 1] = vec[j]; // shift right
         j--; // move left
      }
      vec[j + 1] = key; // insert the key
   }
}


int main(){
  
  int n;
  cin >> n;
  vector < int > vec(n);
  for (auto& i: vec) cin >> i;
  insertion_sort(vec);
  for (auto& i: vec) cout << i << " ";  

}