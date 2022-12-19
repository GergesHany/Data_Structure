#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;



class circular_linked_list{
  
private:  
 struct node{
    int item;
    node *next;
    node(int val){
        item = val;
        next = nullptr;
    }
 };    

  int length;
  node *head, *tail;


public:

  // Constructor to initialize the linked list
  circular_linked_list(){
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
    if (is_empty()) head = tail = New_node, tail -> next = head;
    else {
        New_node -> next = head;
        head = New_node;
        tail -> next = head;
    }
    length++;
  }

  // insert a new node at the end of the list
  void insert_end(int val){
        node* New_node = new node(val);
        if (is_empty()) head = tail = New_node, New_node -> next = head;
        else{
            tail -> next = New_node;
            tail = New_node;
            tail -> next = head;
        }
        length++;
  }    

   // search for a specific value in the list
   ll find_pos(int val){
        node *temp = head;
        for (int i = 0; i < length; i++){
            if (temp -> item == val) return i;
            temp = temp -> next;
        }
        return -1;
   } 

   // update a specific value in the list
    void update(int pos, int new_val){
        if (pos < 0 || pos >= length) {
            cout << "Index out of range" << "\n";
            return;
        }

        node *temp = head;
        for (int i = 0; i < pos; i++) temp = temp -> next;
        temp -> item = new_val;
    }

    // delete a first node in the list
    void delete_first(){
        if (is_empty()) {
            cout << "List is empty" << "\n";
            return;
        }
        if (length == 1) head = tail = nullptr;
        else{
            node* New_node = head;
            head = head -> next;
            tail -> next = head;
            delete New_node;
        }
        length--;
    }
    
    // delete a last node in the list
    void delete_end(){
        if (is_empty()) {
            cout << "List is empty" << "\n";
            return;
        }
        if (length == 1) head = tail = nullptr; 
        else{
            node* new_node = head;
            while(new_node -> next != tail) new_node = new_node -> next;
            delete tail;
            tail = new_node;
            tail -> next = head;
        }
        length--;
    }
    

    // print the list 
    void print(){
        if (is_empty()) {
            cout << "List is empty" << "\n";
            return;
        }
        node *temp = head;
        do{
            cout << temp -> item << " ";
            temp = temp -> next;
        }while(temp != head);
        cout << "\n";
    }

    // return the length of the list
    int sz(){
        cout << "length = ";
        return length;
    }

    // get min value in the list
    int get_min(){
        if (is_empty()) {
            cout << "List is empty" << "\n";
            return -1;
        }
        node *temp = head;
        int min_val = temp -> item;
        while(temp != tail){
            temp = temp -> next;
            min_val = min(min_val, temp -> item);
        }
        return min_val;
    }

    // get max value in the list
    int get_max(){
        if (is_empty()) {
            cout << "List is empty" << "\n";
            return -1;
        }
        node *temp = head;
        int max_val = temp -> item;
        while(temp != tail){
            temp = temp -> next;
            max_val = max(max_val, temp -> item);
        }
        return max_val;
    }

    // check the value is in the list or not
    bool serach(int val){
        if (is_empty()) {
            cout << "List is empty" << "\n";
            return false;
        }
        node *temp = head;
        while(temp != tail){
            if (temp -> item == val) return true;
            temp = temp -> next;
        }
        return (temp -> item == val);
    }

    // delete at specific position
    void delete_at_pos(int pos){
        if (pos < 0 || pos >= length) {
            cout << "Index out of range" << "\n";
            return;
        }
        if (pos == 0) delete_first();
        else if (pos == length - 1) delete_end();
        else{
            node *temp = head;
            for (int i = 0; i < pos - 1; i++) temp = temp -> next;
            node *new_node = temp -> next;
            temp -> next = new_node -> next;
            delete new_node;
            length--;
        }
    }

    // insert at specific position
    void insert_at_pos(int pos, int val){
        if (pos < 0 || pos > length) {
            cout << "Index out of range" << "\n";
            return;
        }
        if (pos == 0) insert_first(val);
        else if (pos == length) insert_end(val);
        else{
            node *temp = head;
            for (int i = 0; i < pos - 1; i++) temp = temp -> next;
            node *new_node = new node(val);
            new_node -> next = temp -> next;
            temp -> next = new_node;
            length++;
        }
    }

    // add new node before the node that has the value
    void add_before(int val, int new_val){
        int pos = find_pos(val);
        if (pos == -1) {
            cout << "Value not found" << "\n";
            return;
        }
        if (pos == 0) insert_first(new_val);
        else if (pos == length - 1) insert_end(new_val);
        else insert_at_pos(pos, new_val);
    }

    // delete the node that after a node that has the specified value
    void delete_after(int val){
        int pos = find_pos(val);
        if (pos == -1) {
            cout << "Value not found" << "\n";
            return;
        }
        if (pos == 0) delete_first();
        else if (pos == length - 1) delete_end();
        else delete_at_pos(pos + 1);
    }
  
     // delete the list
    ~circular_linked_list(){
        if (is_empty()) return;
        node *temp = head;
        while(temp != tail){
            node *new_node = temp;
            temp = temp -> next;
            delete new_node;
        }
        delete tail;
    }

};



int main()
{

   circular_linked_list list;
   list.insert_first(1);
   list.insert_first(2);

   list.insert_end(3);
   list.insert_end(4);

   list.print(); // 2 1 3 4
   list.delete_at_pos(2);
   list.print(); // 2 1 4
   list.insert_at_pos(2, 5);
   list.print(); // 2 1 5 4
   list.add_before(5, 6);
   list.print(); // 2 1 6 5 4
   list.delete_after(6);
   list.print(); // 2 1 6 4
   for (int i = 1; i <= 4; i++) list.insert_end(i * 10);
   list.print(); // 2 1 6 4 10 20 30 40

   cout << (list.serach(1) ? "Found" : "Not found") << "\n";
   cout << "min: " << list.get_min() << "\n"; // min: 1
   cout << "max: " << list.get_max() << "\n"; // max: 40
   cout << "length: " << list.sz() << "\n"; // length: 8
   
   
  return 0;
}