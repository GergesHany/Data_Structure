#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// best case: O(n) // when the array is sorted
// average case: O(n^2) // when the array is reverse sorted or random
// Time Complexity: O(n^2) // when the array is reverse sorted or random

void Bubble_Sort(vector < ll >& vec){
   for (int i = 0; i < sz(vec); i++){
      bool swapped = false; // to check if the array is sorted
       // "(j < sz(vec) - i - 1)" because the last i elements are already sorted
      for (int j = 0; j < sz(vec) - i - 1; j++){
         if (vec[j] > vec[j + 1]){ // if the current element is greater than the next element
            swap(vec[j], vec[j + 1]);
            swapped = true; // assign the value of true to swap to check if the array is sorted
         }
      }
      if (!swapped) break; // if the array is sorted then break the loop because the array is sorted
   }
}


int main(){
  
  int n;
  cin >> n;
  vector < ll > vec(n);
  for (auto& i: vec) cin >> i;
  Bubble_Sort(vec);
  for (auto& i: vec) cout << i << " ";


}