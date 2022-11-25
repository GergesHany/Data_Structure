#include <iostream>
#define ll long long

using namespace std; 

// stack is a data structure that follows the LIFO (last in first out) 


class Stack{
  
  public:
    int *arr; 
    int size; 
    int capacity; 
  
  Stack(){
    size = 0;
    capacity = 1;
    arr = new int[capacity]; 
  }
  
  void push(int val){
    if (size == capacity){ 
      int *temp = new int[2 * capacity]; 
      for (int i = 0; i < size; i++){
        temp[i] = arr[i];
      }
      delete arr;
      capacity *= 2;
      arr = temp;
    }
    arr[size++] = val;
  }
  
  void pop(){
    if (size == 0) return void(cout << "Stack is empty");
    size--;
  }
  
  int top(){
    if (size == 0) { 
      cout << "Stack is empty";
      return -1;
    }
    return arr[size - 1];
  }
  
  int get_size(){
    return size;
  }
  
  int get_capacity(){
    return capacity;
  }
  
  bool is_empty(){
    return size == 0;
  }
  
  void print(){
    for (int i = 0; i < size; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  
  ~Stack(){
    delete arr;
  }
  
};



int main(){


   Stack st;
   st.push(3);
   st.push(4);
   st.push(5);
   st.push(6);

   st.print();

   st.pop();

   st.print();


    return 0;
}