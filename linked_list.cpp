#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;


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

  node *first;
  node *last;
  int length;

public:
  linked_list(){
    length = 0;
    first = last = nullptr;
  }  

  bool is_empty(){ 
    return first == nullptr;
  }
  
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

  void delete_at_pos(ll pos){
    if (is_empty()) cout << "List is empty";
    else if (pos < 0 or pos > length) {
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
   

    void print(){
        node *temp = first;
        while(temp != nullptr){
            cout << temp -> item << " ";
            temp = temp -> next;
        }
        cout << "\n";
    } 
    
    bool search(ll val){
        node *temp = first;
        while(temp != nullptr){
            if (temp -> item == val) return true;
            temp = temp -> next;
        }
        return false;
    }

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

    ll find_pos(ll val){
        node *temp = first;
        for (int i = 0; i < length; i++){
            if (temp -> item == val) return i + 1; // return position
            temp = temp -> next;
        }
        return -1; // not found
    }

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


    ll Idx = lest.find_pos(100); // return position of 100 in list based on 1
    cout << Idx << "\n";
    cout << (lest.search(100) ? "Found" : "Not Found") << "\n";
    cout << (lest.search(1000) ? "Found" : "Not Found") << "\n";

    lest.update(Idx - 1, 1000); // update value at position Idx - 1 
    cout << (lest.search(1000) ? "Found" : "Not Found") << "\n";

    cout << (lest.search(lest.find_pos(1000) - 1) ? "Found" : "Not Found") << "\n";

    lest.print();


  return 0;
}
