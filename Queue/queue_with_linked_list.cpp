#include <bits/stdc++.h>
using namespace std; 

template < typename T = int > class Queue {
    struct Node {
        T data;
        Node *next;
        Node(T data) : data(data), next(nullptr) {}
    };

    int size;
    Node *front, *rear;

public:

    Queue() : front(nullptr), rear(nullptr), size(0) {}
    
    // push data to the queue
    void push(T data) {
        Node *newNode = new Node(data);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // pop data from the queue
    void pop() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }
    
    // get the front element of the queue
    T getFront() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // get the rear element of the queue
    T getRear() {
        if (rear == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }

    // get the size of the queue
    T getSize() {
        return size;
    }

    // check if the queue is empty
    T isEmpty() {
        return size == 0;
    }

    // print the queue
    void print() {
        Node *temp = front;
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << '\n';
    }

    // destructor
    ~Queue() {
        while (front != nullptr) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    // get the size of the queue
    T get_size() {
        return size;
    }
    
    // get the max element in the queue
    T get_max(){
       T ans = 0;
       Node *temp = front;
        while (temp != nullptr) {
            ans = max(ans, temp->data);
            temp = temp->next;
        }
      return ans;  
    }
    
    // get the min element in the queue
    T get_min(){
       T ans = 1e9;
       Node *temp = front;
        while (temp != nullptr) {
            ans = min(ans, temp->data);
            temp = temp->next;
        }
      return ans;  
    }
  
   // find the index of the element x in the queue
   T find_index(int x){
      T index = 0;
      Node *temp = front;
      while (temp != nullptr) {
          if(temp->data == x) return index;
          index++;
          temp = temp->next;
      }
      return -1; // if the element is not found
   }

  // check if the queue is sorted or not
  T is_sorted(){
    Node *temp = front;
    while (temp != nullptr) {
        if(temp->next != nullptr && temp->data > temp->next->data) return false;
        temp = temp->next;
    }
    return true;
  }
  
  // enqueue N that will enqueue an array of N elements on the queue
  void enqueue_N(int N, int* arr){
    for(int i = 0; i < N; i++) push(arr[i]);
  }

  // dequeue N that will dequeue and return an array of N elements from the queue
  T* dequeue_N(int N){
    if (size < N || N < 0) return nullptr;
    int sz = size; // save the size of the queue
    T *arr = new T[N];
    T *temp = new T[sz + 1];
    for(int i = 0; i < N; i++)
      arr[i] = getFront(), temp[i] = getFront(), pop();
    for(int i = N; i < sz; i++) temp[i] = getFront(), pop();
    for(int i = 0; i < sz; i++) push(temp[i]);
    return arr;
  }
  
  // get the sum of the elements in the queue
  T get_sum(){
    T sum = 0;
    Node *temp = front;
    while (temp != nullptr) {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
  }

  // get the average of the elements in the queue
  T get_average(){
    return (!size ? 0 : get_sum() / size);
  }

};


int main()
{


  Queue < int > q;
  for (int i = 1; i <= 10; i++) q.push(i);
  q.print();
  
  cout << "The size of the queue equal " << q.get_size() << "\n"; // 10
  cout << "The front element in the queue equal " << q.getFront() << "\n"; // 1
  cout << "The rear element in the queue equal " << q.getRear() << "\n"; // 10
  
  q.pop();
  q.print(); // 2 3 4 5 6 7 8 9 10
  
  
  cout << "is empty: " << q.isEmpty() << '\n'; // 0
  cout << "The minimum element in the queue equal " << q.get_min() << "\n"; // 2
  cout << "The maximum element in the queue equal " << q.get_max() << "\n"; // 10
  cout << "The sum of all elements in the queue equal " << q.get_sum() << "\n"; // 54

  cout << "find_index 5 : " << q.find_index(5) << '\n'; // 3
  cout << "find_index 11 : " << q.find_index(11) << '\n'; // -1
  
  
  q.print(); // 7 8 9 10
  q.enqueue_N(5, new int[5]{11, 12, 13, 14, 15});
  q.print(); // 7 8 9 10 11 12 13 14 15
 
 
  int N = 10;
  int *arr = q.dequeue_N(N);
  if (arr != nullptr) 
      for (int i = 0; i < N; i++) 
        cout << arr[i] << " \n"[i == N - 1]; // 2 3 4 5 6 7 8 9 10 11
  else {
    cout << "NULL" << "\n";
    cout << (N < 0 ? "N is negative" : "N is greater than the queue size") << "\n";
  }

  q.print(); // 2 3 4 5 6 7 8 9 10 11 12 13 14 15


  return 0;
}

