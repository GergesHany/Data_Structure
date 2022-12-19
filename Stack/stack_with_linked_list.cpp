#include <bits/stdc++.h>
using namespace std; 
#define sz(s) int(s.size())  


// implementation of stack using linked list
template < typename T = int > class Stack{
  
  public:
    struct Node{
      T data;
      Node *next;
    };


    int size;  // the number of elements in the stack
    Node *head; // the top element in the stack
  
  // constructor
  Stack(){
    head = nullptr;
    size = 0;
  }
  
  // add an element to the top of the stack
  void push(T val){ 
    Node *temp = new Node;
    temp -> data = val;
    temp -> next = head;
    head = temp;
    size++;
  }
  
  // remove the top element
  void pop(){ 
    if (size == 0) {
      cout << "Stack is empty";
      return;
    }
    Node *temp = head;
    head = head -> next;
    delete temp;
    size--;
  }
  
  // return the top element
  T top(){ 
    if (size == 0) { 
      cout << "Stack is empty";
      return -1;
    }
    return head->data;
  }
  
  // return the size of the stack
  int get_size(){
    return size; 
  }
  
  // check if the stack is empty
  bool is_empty(){ 
    return size == 0;
  }
  
  // print the stack
  void print(){ 
    Node *temp = head;
    while (temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }
  
  ~Stack(){
    Node *temp = head;
    while (temp){
      Node *temp2 = temp;
      temp = temp->next;
      delete temp2;
    }
  }

  bool is_plandrom(string s){ 
    Stack < char > st;
    for (int i = 0; i < s.size(); i++)  st.push(s[i]); 
    for (int i = 0; i < s.size(); i++){
      if (st.top() != s[i]){ 
        cout << "Not plandrom " << s << "\n";
        return false;
      }
      st.pop();
    }
    cout << "Plandrom " << s << "\n";
    return true;
  }

  string binary(int n){
    Stack < char > st;
    int temp = n;
    while (n){
      st.push(n % 2); // push() is used to add an element to the top of the stack
      n /= 2; 
    }
    string s;
    while (!st.is_empty()){
      s += st.top() + '0'; // top() is used to return the top element
      st.pop(); // pop() is used to remove the top element
    }
    cout << "Binary of " << temp << " is: ";
    return s;
  }

};

int main(){
  

  Stack < char > st;
  string s = "abba";
  st.is_plandrom(s);
  
  Stack < int > st2;
  for (int i = 0; i < 10; i++) st2.push(i);
  st2.print();

  return 0;
}