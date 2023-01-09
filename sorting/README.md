**${\bf{\color\{Green}\{A-collection-of-sorting-algorithms-implemented-in-C++}}}$**


## Selection Sort

### Code

```cpp
void Selection_Sort_1(vector < ll >& vec){
   for (int i = 0; i < sz(vec); i++){
      int Idx_mn = i; // Idx_mn is the index of the minimum element
      for (int j = i + 1; j < sz(vec); j++) // "j = i + 1" because the first i elements are already sorted 
         if (vec[j] < vec[Idx_mn]) Idx_mn = j; // if the current element is less than the minimum element
      swap(vec[i], vec[Idx_mn]); // swap the minimum element with the current element 
   }
}

void Selection_Sort_2(vector < ll >& vec){
    for (int i = sz(vec) - 1; i >= 0; i--){
        int Idx_mx = i; // Idx_mx is the index of the maximum element
        for (int j = i - 1; j >= 0; j--)  // "j = i - 1" because the last i elements are already sorted
            if (vec[j] > vec[Idx_mx]) Idx_mx = j; // if the current element is greater than the maximum element
        swap(vec[i], vec[Idx_mx]); // swap the maximum element with the current element
    }
}


void Selection_Sort_3(vector < ll >& vec){
   for (int i = sz(vec) - 1; i >= 0; i--){
      int Idx_mx = i; // Idx_mx is the index of the maximum element
      for (int j = 0; j < i; j++) // "j < i" because the last i elements are already sorted
        if (vec[j] > vec[Idx_mx]) Idx_mx = j; // if the current element is greater than the maximum element
      swap(vec[i], vec[Idx_mx]); // swap the maximum element with the current element    
   }
}
```



Selection sort is noted for its simplicity, and it has performance advantages over more complicated algorithms in certain situations, particularly where auxiliary memory is limited

| Case  | Performance |
| :---: | :---: |
| Worst case performance   | O(n^2)  |
| Best case performance  | O(n^2)  |
| Average case performance  | O(n^2)  |
| Auxiliary Space           | O(1)  |

![selectionsort](https://user-images.githubusercontent.com/36489953/42171344-5554d9d2-7e19-11e8-8537-7811ebbbd1b6.gif)


## Bubble Sort

### Code

```cpp
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
```


A slow sorting algorithm for the simplest data sets

| Case  | Performance |
| :---: | :---: |
| Worst case performance   | O(n^2)  |
| Average case performance  | O(n^2)  |
| Auxiliary Space           | O(1)  |


**${\bf{\color\{Red}\{important-Note}}}$**
 
The Best  case in Bubble sort is O(N ^ 2) and 
The Best  case in Bubble sort Early Termination is O(N)

![bubble-sort-gif-9](https://user-images.githubusercontent.com/36489953/42171410-83532a64-7e19-11e8-95a1-b2dd3aaedc43.gif)


## Insertion Sort

### Code

```cpp
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
```

Insertion sort is a simple sorting algorithm that works the way we sort playing cards. It is efficient for (quite) small data sets.  
It is often used when the data set is nearly sorted (it takes minimum time (Order of n)).    
It takes maximum time to sort if elements are sorted in reverse order.
 

| Case  | Performance |
| :---: | :---: |
| Worst case performance   | O(n^2)  |
| Best case performance  | O(n)  |
| Average case performance  | O(n^2)  |
| Auxiliary Space           | O(1)  |

![1_kra0ofxedgi8hvhjffci4w](https://user-images.githubusercontent.com/36489953/42171484-b508016a-7e19-11e8-8d47-3b95d788d579.gif)

## Merge Sort

```cpp
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
```

Merge Sort is a Divide and Conquer algorithm that continually splits a list in half and then merge the sublists in a sorted way.    
A single most important advantage of merge sort over quick sort is its stability: the elements compared equal retain their original order.  


| Case  | Performance |
| :---: | :---: |
| Worst case performance   | O(n log n)  |
| Best case performance  | O(n log n)  |
| Average case performance  | O(n log n)  |
| Auxiliary Space           | O(n)  |  


![merge-sort-example-300px](https://user-images.githubusercontent.com/36489953/42171944-ed5814c8-7e1a-11e8-9d30-10ae8047bb17.gif)


