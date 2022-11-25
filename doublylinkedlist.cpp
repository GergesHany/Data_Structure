#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;



class doubly_linked_list{
  
private:  
 struct node{
    int item;
    node *next, *prev;
    node(int val){
        item = val;
        next = prev = nullptr;
    }
 };    

  int length;
  node *head, *tail;

public:
  
   // Constructor to initialize the linked list 
  doubly_linked_list(){
    length = 0;
    head = tail = nullptr;
  }

    // check if the list is empty
    bool is_empty(){
        return head == nullptr;
    }

    // insert a new node at the front of the list
    void insert_first(int val){
        node* New_node = new node(val);
        if (is_empty()) {
            head = tail = New_node;
            New_node -> next = New_node -> prev = nullptr;
        }
        
        else{    
          New_node -> next = head;
          New_node -> prev = nullptr;
          head -> prev = head;
          head = New_node;
        }
          length++;
    }

    // insert a new node at the end of the list
    void insert_end(int val){
        node* New_node = new node(val);
        if (is_empty()) {
            head = tail = New_node;
            New_node -> next = New_node -> prev = nullptr;
        }
        else{
          New_node -> prev = tail;
          New_node -> next = nullptr;
          tail -> next = New_node;
          tail = New_node;
        }
        length++;
    }

    // print the list
    void print(){
        node* temp = head;
        while (temp != nullptr){
            cout << temp -> item << " ";
            temp = temp -> next;
        }
        cout << "\n";
    }

    // search for a specific value in the list
    bool search(int val){
        node* temp = head;
        while (temp != nullptr){
            if (temp -> item == val) return true;
            temp = temp -> next;
        }
        return false;
    }

    // find the pos of a specific value in the list
    int find(int val){
        node* temp = head;
        for (int i = 0; i < length; i++){
            if (temp -> item == val) return i;
            temp = temp -> next;
        }
        return -1; // not found
    }

    // find pos of the first node with a specific value
    int find_first(int val){
        node* temp = head;
        for (int i = 0; i < length; i++){
            if (temp -> item == val) return i;
            temp = temp -> next;
        }
        return -1; // not found
    }

    // find pos of the last node with a specific value
    int find_last(int val){
        node* temp = tail;
        for (int i = length - 1; i >= 0; i--){
            if (temp -> item == val) return i;
            temp = temp -> prev;
        }
        return -1; // not found
    }

    // get min value in the list
    int min(){
        node* temp = head;
        int min = temp -> item;
        while (temp != nullptr){
            if (temp -> item < min) min = temp -> item;
            temp = temp -> next;
        }
        return min;
    }

    // get max value in the list
    int max(){
        node* temp = head;
        int max = temp -> item;
        while (temp != nullptr){
            if (temp -> item > max) max = temp -> item;
            temp = temp -> next;
        }
        return max;
    }

    // get the sum of all values in the list
    int sum(){
        node* temp = head;
        int sum = 0;
        while (temp != nullptr){
            sum += temp -> item;
            temp = temp -> next;
        }
        return sum;
    }

    // update the value of a specific node
    void update(int pos, int val){
        node* temp = head;
        for (int i = 0; i < pos; i++){
            temp = temp -> next;
        }
        temp -> item = val;
    }

    // delete the last node in the list
    void delete_last(){
        if (is_empty()) {
            cout << "The list is empty\n";
            return;
        }
        if (length == 1){
            delete head;
            head = tail = nullptr;
        }
        else{
            node* temp = tail;
            tail = tail -> prev;
            tail -> next = nullptr;
            delete temp;
        }
        length--;
    }

    // delete the first node in the list
    void delete_first(){
        if (is_empty()) {
            cout << "The list is empty\n";
            return;
        }
        if (length == 1){
            delete head;
            head = tail = nullptr;
        }
        else{
            node* temp = head;
            head = head -> next;
            head -> prev = nullptr;
            delete temp;
        }
        length--;
    }



};



void Accepted(){
  

  doubly_linked_list list;
  list.insert_first(1);
  list.insert_first(2);
  list.insert_first(3);

  list.print();     


}

int main()
{

  int testcaces = 1;
  // cin >> testcaces;
  while (testcaces--){  
    Accepted();
  }   
  return 0;
}