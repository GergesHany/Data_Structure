#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) int(s.size())

// best case: O(n) // when the array is sorted
// average case: O(n^2) // when the array is reverse sorted or random
// Time Complexity: O(n^2) // when the array is reverse sorted or random
void Selection_Sort_1(vector < ll >& vec){
   for (int i = 0; i < sz(vec); i++){
      int mn = i; // mn is the index of the minimum element
      for (int j = i + 1; j < sz(vec); j++) // "j = i + 1" because the first i elements are already sorted 
         if (vec[j] < vec[mn]) mn = j; // if the current element is less than the minimum element
      swap(vec[i], vec[mn]); // swap the minimum element with the current element 
   }
}

void Selection_Sort_2(vector < ll >& vec){
    for (int i = sz(vec) - 1; i >= 0; i--){
        int mx = i; // mx is the index of the maximum element
        for (int j = i - 1; j >= 0; j--)  // "j = i - 1" because the last i elements are already sorted
            if (vec[j] > vec[mx]) mx = j; // if the current element is greater than the maximum element
        swap(vec[i], vec[mx]); // swap the maximum element with the current element
    }
}


void Selection_Sort_3(vector < ll >& vec){
   for (int i = sz(vec) - 1; i >= 0; i--){
      int mx = i; // mx is the index of the maximum element
      for (int j = 0; j < i; j++) // "j < i" because the last i elements are already sorted
        if (vec[j] > vec[mx]) mx = j; // if the current element is greater than the maximum element
      swap(vec[i], vec[mx]); // swap the maximum element with the current element    
   }
}


int main(){
  
  int n;
  cin >> n;
  vector < ll > vec(n);
  for (auto& i: vec) cin >> i;
  Selection_Sort_3(vec);
  for (auto& i: vec) cout << i << " ";


}