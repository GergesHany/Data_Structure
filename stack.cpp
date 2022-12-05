#include <iostream>
#define ll long long

using namespace std; 


class Stack{
  
  public:
    int *arr; // pointer to the array that will store the stack elements
    int size;  // the number of elements in the stack
    int capacity = 1e7; // the maximum capacity of the stack
  
  // constructor
  Stack(){
    size = 0;
    capacity = 1;
    arr = new int[capacity]; 
  }
  
  // add an element to the top of the stack
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
  
  // remove the top element
  void pop(){ 
    if (size == 0) return void(cout << "Stack is empty");
    size--;
  }
  
  // return the top element
  int top(){ 
    if (size == 0) { 
      cout << "Stack is empty";
      return -1;
    }
    return arr[size - 1];
  }
  
  // return the size of the stack
  int get_size(){
    return size; 
  }
  
  // return the capacity of the stack
  int get_capacity(){
    return capacity; 
  }
  
  // check if the stack is empty
  bool is_empty(){ 
    return size == 0;
  }
  
  // print the stack
  void print(){ 
    for (int i = 0; i < size; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  
  ~Stack(){
    delete arr; // free the memory
  }

  ll find_pos(int val){
    for (int i = 0; i < size; i++){
      if (arr[i] == val) return i; // return the position of the value
    }
    cout << "Value not found "; 
    return -1; // if the value is not found
  }

  // check if the string is plandrom or not
  bool is_plandrom(string s){ 
    Stack st;
    for (int i = 0; i < s.size(); i++){
      st.push(s[i]); // push char as int .. The ASCII value of 'a' is 97, 'b' is 98, and so on
    }
    for (int i = 0; i < s.size(); i++){
      if (char(st.top()) != s[i]){ // char() is used to convert int to char 
        cout << "Not plandrom " << s << "\n";
      }
      st.pop();
    }
    cout << "Plandrom " << s << "\n";
    return true;
  }

  // convert decimal to binary
  string binary(ll n){
    Stack st;
    int temp = n;
    while (n){
      st.push(n % 2); // push() is used to add an element to the top of the stack
      n /= 2; 
    }
    string s;
    while (!st.is_empty()){
      s += st.top() + '0'; // '0' is used to convert int to char
      st.pop(); // pop() is used to remove the top element from the stack
    }
    cout << "Binary of " << temp << " is: ";
    return s;
  }
  
};


int main(){

  Stack st;

  st.is_plandrom("abba");
  cout <<  st.binary(7) << "\n";

  return 0;
}
