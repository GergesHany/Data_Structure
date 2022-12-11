#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct Circular_queue{
    
    int *Circular; // pointer to array of elements in the queue
    int Front, rear, size; 

    // constructor
    Circular_queue(){
        Front = rear = 0; // initially the queue is empty
        size = 1e7; // the maximum size of the queue
        Circular = new int[size]; // allocating the memory
    }

    // return The queue is empty or not
    bool is_empty(){
        return (rear % size) == Front;
    }

    // return The queue is full or not
    bool is_full(){
        return (Front == 0 && rear == size - 1) or (rear + 1 == Front);
    }

    // push element at the end of the queue
    void push(int val){
        if (is_full()) {
            cout << "The queue is full\n";
            return;
        }
        Circular[(++rear) % size] = val;
    }

    // pop element from the front of the queue
    void pop(){
        if (is_empty()){
            cout << "The queue is empty\n";
            return;
        }
        Front++;
    }

    // display the queue
    void disiply(){
        for (int i = Front + 1; i <= rear; i++)
            cout << Circular[i % size] << " \n"[i == rear];
    }


    // return the index of an element in the queue
    int find_index(int x){
        for(int i = Front + 1; i <= rear; i++)
            if(Circular[i % size] == x) return i;
        return -1;
    }


    // return the front element of the queue
    int front(){
        if(Front == rear){
            cout << "Queue is empty" << "\n";
            return -1; // if the queue is empty return -1
        }
        return Circular[(Front + 1) % size];
    }

    // return the back element of the queue
    int back(){
        if(Front == rear){
            cout << "Queue is empty" << "\n";
            return -1; // if the queue is empty return -1
        }
       return Circular[rear % size]; 
    }

    int sz(){
        return rear - Front;
    }

};

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}


int main(){
    
    Gerges_Hany();
    Circular_queue q;
    for (int i = 1; i <= 6; i++) q.push(i * 10);
    q.disiply();
    q.disiply();
    q.push(70);
    q.disiply();

    cout << q.front() << "\n";
    cout << q.back()  << "\n";

    cout << q.find_index(80) << "\n";
    cout << q.find_index(60) << "\n";

    cout << q.sz() << "\n";
    q.pop();
    cout << q.sz() << "\n";


}