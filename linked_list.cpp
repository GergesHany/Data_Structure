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
    ll search(ll val){
        node *temp = first;
        for (int i = 0; i < length; i++){
            if (temp -> item == val) return i;
            temp = temp -> next;
        }
        return -1;
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

  // add new node before the node that has the value
  void addbefore(int val, int data){
    int pos = search(val);
    if (pos == -1) cout << "Value not found" << "\n";
    else if (pos == 0) cout << "Value is the first element" << "\n";
    else insert_at_pos(pos, data);
  }

   // delete the node that after a node that has the specified value
   void delete_after(int val){
      int pos = search(val);
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



void Accepted(){
  
  linked_list lest;
  lest.insert_first(10);
  lest.insert_first(20);
  lest.insert_first(30);
  lest.insert_first(40);
  
  lest.insert_first(40);
  lest.insert_first(30);
  lest.insert_first(20);
  lest.insert_first(10);
  lest.insert_end(100);

  lest.print();  

  ll Idx = lest.find_pos(100); // return position of 100 in list based on 1
  cout << Idx << "\n";
  cout << (lest.search(100) ? "Found" : "Not Found") << "\n";
  cout << (lest.search(1000) ? "Found" : "Not Found") << "\n";
  
  lest.update(Idx, 1000); // update value at position Idx
  cout << (lest.search(1000) != -1 ? "Found" : "Not Found") << "\n";

  lest.print();
  

}

int main()
{

  Gerges_Hany();
  int testcaces = 1;
  // cin >> testcaces;
  while (testcaces--){  
    Accepted();
  }   
  return 0;
}
