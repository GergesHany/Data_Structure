#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;


void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}


class linked_list{
  
private:  
 struct node{
    int item;
    node *next;
    node(int val){
        item = val;
        next = nullptr;
    }
 };    

  node *first, *last;
  int length;

public:
  // Constructor to initialize the linked list 
  linked_list(){
    length = 0;
    first = last = nullptr;
  }  

  // determine whether or not the list is empty
  bool is_empty(){ 
    return first == nullptr;
  }
  
  // insert a new node at the front of the list
  void insert_first(ll val){
    node *temp = new node(val);
    if(is_empty()){
      first = last = temp;
      temp ->next = nullptr;
    }
    
    else{
        temp -> next = first;
        first = temp;
    }
    length++;
  }


  // insert a new node at the end of the list
  void insert_end(ll val){
    node *temp = new node(val);
    if (is_empty()){
        first = last = temp;
        temp -> next = nullptr;
    }
    else{
        last -> next = temp;
        last = temp;
        last -> next = nullptr; 
    }
    length++;
  }

  // insert a new node at a specific position in the list
  void insert_at_pos(ll pos, ll val){
    if (pos < 0 or pos > length) {
        cout << "Index out of bound" << "\n";
        return;
    }
    if (pos == 0) insert_first(val);
    else if (pos == length) insert_end(val);
    else{
        node *newNode = new node(val);
        node *temp = first;
        for (int i = 0; i < pos - 1; i++)
            temp = temp -> next;
        newNode -> next = temp -> next;
        temp -> next = newNode;    
        length--;
    }
    length++;
  }

   // delete the first node in the list
   void delete_first(){
        if (is_empty()) {
            cout << "List is empty" << "\n";
            return;
        }
        node *temp = first;
        first = first -> next;
        delete temp;
        length--;
   } 

   // delete the last node in the list
   void delete_end(){
      if (is_empty()) cout << "List is empty";
      else{
         node *temp = first;
         while(temp -> next != last)
            temp = temp -> next;
        delete last;
        last = temp;
        last -> next = nullptr;
        length--;
      }
   }
   
   // delete a node at a specific position in the list
   void delete_at_pos(ll pos){
        if (pos < 0 or pos > length) {
            cout << "Index out of bound" << "\n";
            return;
        }
        if (pos == 0) delete_first();
        else if (pos == length) delete_end();
        else{
            node *temp = first;
            for (int i = 0; i < pos - 1; i++)
                temp = temp -> next;
            node *temp2 = temp -> next;
            temp -> next = temp2 -> next;
            delete temp2;
        }
   }

    // search for a specific value in the list
    void print(){
        node *temp = first;
        while(temp != nullptr){
            cout << temp -> item << " ";
            temp = temp -> next;
        }
        cout << "\n";
    } 
    
    // search for a specific value in the list
    bool search(ll val){
        node *temp = first;
        for (int i = 0; i < length; i++){
            if (temp -> item == val) return true;
            temp = temp -> next;
        }
        return false;
    }
 
    // update a specific value in the list
    void update(ll pos, ll val){
        if (pos < 0 or pos > length) {
            cout << "Index out of bound" << "\n";
            return;
        }
        node *temp = first;
        for (int i = 0; i < pos; i++)
            temp = temp -> next;
        temp -> item = val;
    }

   // find the pos of a specific value in the list
    ll find_pos(ll val){
        node *temp = first;
        for (int i = 0; i < length; i++){
            if (temp -> item == val) return i; // return position
            temp = temp -> next;
        }
        return -1; // not found
   }
  
  // return the length of the list
  ll get_length(){
    return length;
  }

  // return the minimum value in the list
  ll get_min_element(){
    node *temp = first;
    ll min = temp -> item;
    for (int i = 0; i < length; i++){
      if (temp -> item < min) min = temp -> item;
      temp = temp -> next;
    }
    return min;
  }

   // return the maximum value in the list
  ll get_max_element(){
    node *temp = first;
    ll max = temp -> item;
    for (int i = 0; i < length; i++){
      if (temp -> item > max) max = temp -> item;
      temp = temp -> next;
    }
    return max;
  }

  // add new node before the node that has the value
  void addbefore(int val, int data){
    int pos = find_pos(val);
    if (pos == -1) cout << "Value not found" << "\n";
    else if (pos == 0) cout << "Value is the first element" << "\n";
    else insert_at_pos(pos, data);
  }

   // delete the node that after a node that has the specified value
   void delete_after(int val){
      int pos = find_pos(val);
      if (pos == -1) cout << "Value not found" << "\n";
      else if (pos == length - 1) cout << "Value is the last element" << "\n";
      else delete_at_pos(pos + 1);
   }

  // delete the list
  ~linked_list(){
    node *temp = first;
    while(temp != nullptr){
        node *temp2 = temp;
        temp = temp -> next;
        delete temp2;
    }
    first = last = nullptr;
  }


};





int main()
{

  linked_list list;
  for (int i = 1; i <= 10; i++) list.insert_end(i);
  list.print(); // 1 2 3 4 5 6 7 8 9 10
  list.insert_first(0);
  list.print(); // 0 1 2 3 4 5 6 7 8 9 10
  list.insert_end(11); // 0 1 2 3 4 5 6 7 8 9 10 11
  list.insert_at_pos(5, 100); // 0 1 2 3 4 100 5 6 7 8 9 10 11
  list.delete_first(); // 1 2 3 4 100 5 6 7 8 9 10 11
  list.delete_end(); // 1 2 3 4 100 5 6 7 8 9 10
  list.print(); // 1 2 3 4 100 5 6 7 8 9 10

  cout << "Length: " << list.get_length() << "\n"; // 11
  cout << "Min: " << list.get_min_element() << "\n"; // 1
  cout << "Search for 100: " << list.search(100) << "\n"; // 1
  cout << "Max: " << list.get_max_element() << "\n"; // 100

  
  return 0;
}