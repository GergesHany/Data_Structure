**${\bf{\color\{Red}\{A-collection-of-sorting-algorithms-implemented-in-C++}}}$**


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




