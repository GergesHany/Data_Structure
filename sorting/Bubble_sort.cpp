#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// best case: O(n) // when the array is sorted
// average case: O(n^2) // when the array is reverse sorted or random
// Time Complexity: O(n^2) // when the array is reverse sorted or random

// Bubble sort Early Termination
void Bubble_Sort_1(vector < ll >& vec){
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

void bubble_sort_2(vector < int > &v){
  for(int i = 0; i < sz(v); i++){
    for(int j = 0; j < sz(v) - i - 1; j++){ 
      if(v[j] > v[j + 1]) 
        swap(v[j], v[j + 1]);
    }
  }
}

void Bubble_sort_3(vector < int > &v){
  for(int i = 0; i < sz(v); i++){
    for (int j = i + 1; j < sz(v); j++){
      if(v[i] > v[j]) 
        swap(v[i], v[j]);
    }
  }
}

int main(){
  
  int n;
  cin >> n;
  vector < ll > vec(n);
  for (auto& i: vec) cin >> i;
  Bubble_Sort_1(vec);
  for (auto& i: vec) cout << i << " ";


}
