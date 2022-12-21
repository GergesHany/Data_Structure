#include <bits/stdc++.h>
using namespace std; 

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}


template < typename T = int > struct Queue {
    
    struct Node {
        T data;
        Node *next;
        Node(T data) : data(data), next(nullptr) {}
    };

    int size;
    Node *front, *rear;
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // push an element to the queue 
    void push(T data) {
        Node *node = new Node(data);
        if (front == nullptr) {
            front = rear = node;
            front->next = rear->next = nullptr;
        } else {
            rear->next = node;
            rear = node;
            rear->next = front;
        }
        size++;
    }
    
    // pop an element from the queue
    void pop() {
        if (front == nullptr) return;
        Node *temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
        size--;
    }
    
    // get the front element of the queue
    T getFront() {
       return (is_empty() ? -1 : front->data);
    }
    
    // get the rear element of the queue
    T getRear() {
        return (is_empty() ? -1 : rear->data);
    }
    
    // get the size of the queue
    int getSize() {
        return size;
    }
    
    // check if the queue is empty
    bool is_empty() {
        return size == 0;
    }

    // print the queue
    void print() {
        if (is_empty()) return;
        Node *temp = front;
        while (temp->next != front) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << temp->data << '\n';
    }

    // find the index of an element in the queue
    T find_index(int val){
        if (is_empty()) return -1;
        int index = 0;
        Node *temp = front;
        while (temp->next != front) {
            if(temp->data == val) return index;
            temp = temp->next;
            index++;
        }
        if(temp->data == val) return index;
        return -1;
    }

};


int main()
{
  
    Gerges_Hany();
    Queue < int > q;
    for (int i = 1; i <= 10; i++) q.push(i);
    q.print();
    cout << "The size of the queue is: " << q.getSize() << '\n';
    cout << "The front element of the queue is: " << q.getFront() << '\n';
    cout << "The rear element of the queue is: " << q.getRear() << '\n';
    cout << "The index of 5 in the queue is: " << q.find_index(5) << '\n';
    q.pop();
    q.print();
    cout << "The size of the queue is: " << q.getSize() << '\n';
    cout << "The front element of the queue is: " << q.getFront() << '\n';
    cout << "The rear element of the queue is: " << q.getRear() << '\n';
    cout << "The index of 5 in the queue is: " << q.find_index(5) << '\n';



  return 0;
}

