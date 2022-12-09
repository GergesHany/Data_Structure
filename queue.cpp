#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Queue{
    
    int *Q; // pointer to array of elements in the queue
    int Front, rear, size; 

    // constructor
    Queue(){
        Front = rear = -1;
        size = 10;
        Q = new int[size];
    }

    // push element at the end of the queue
    void push(int x){
        if(rear == size - 1) cout << "Queue is full" << "\n";
        else Q[++rear] = x;
    }
    
    // pop element from the front of the queue
    void pop_front(){
        if(Front == rear){
            cout << "Queue is empty" << "\n";
        }else{
            Front++;
        }
    }

    // pop element from the end of the queue
    void pop_back(){
        if(Front == rear){
            cout << "Queue is empty" << "\n";
        }else{
            rear--;
        }
    }

    // display the queue
    void display(){
        for(int i = Front + 1; i <= rear; i++)
            cout << Q[i] << " \n"[i == rear];
    }

    // return the front element of the queue
    int front(){
        if(Front == rear){
            cout << "Queue is empty" << "\n";
            return -1; // if the queue is empty return -1
        }
        return Q[Front + 1];
    }

    // return the back element of the queue
    int back(){
        if(Front == rear){
            cout << "Queue is empty" << "\n";
            return -1; // if the queue is empty return -1
        }
       return Q[rear]; 
    }

    // check if the queue is empty
    bool empty(){ 
        return Front == rear;
    }

    // return the size of the queue
    int sz(){
        return rear - Front;
    }

    // destructor
    ~Queue(){
        delete []Q;
    }

    // search for an element in the queue
    bool serch(int x){
        for(int i = Front + 1; i <= rear; i++)
            if (Q[i] == x) return true;
        return false;
    }

    // return the maximum element in the queue
    int find_max(){
        int max = INT_MIN;
        for(int i = Front + 1; i <= rear; i++){
            if(Q[i] > max) max = Q[i];
        }
        return max;
    }

    // return the minimum element in the queue
    int find_min(){
        int min = INT_MAX;
        for(int i = Front + 1; i <= rear; i++){
            if(Q[i] < min) min = Q[i];
        }
        return min;
    }

    // return the index of an element in the queue
    int find_index(int x){
        for(int i = Front + 1; i <= rear; i++){
            if(Q[i] == x) return i;
        }
        return -1;
    }

    // insert an element at a specific index
    void insert(int index, int x){
        if(rear == size - 1){
            cout << "Queue is full" << "\n";
        }else{
            for (int i = rear; i >= index; i--) 
                Q[i + 1] = Q[i];
            Q[index] = x; rear++;
        }
    }

    // remove an element at a specific index
    void remove(int index){
        if(Front == rear){
            cout << "Queue is empty" << "\n";
        }else{
            for (int i = index; i < rear; i++) 
                Q[i] = Q[i + 1];
            rear--;
        }
    }

    // reverse the queue
    void reverse(){
        int i = Front + 1, j = rear;
        while(i < j){
            swap(Q[i], Q[j]);
            i++; j--;
        }
    }

    // check if the queue is sorted or not
    bool is_sorted(){
        for (int i = Front + 1; i < rear; i++) 
            if (Q[i] > Q[i + 1]) return false;
        return true;
    } 

    // get the sum of all elements in the queue
    long long get_sum(){
        long long sum = 0;
        for(int i = Front + 1; i <= rear; i++)
            sum += Q[i];
        return sum;
    }

    // sort the queue
    void sort(){
        for (int i = Front + 1; i <= rear; i++) {
            for (int j = i + 1; j <= rear; j++) 
                if (Q[i] > Q[j]) swap(Q[i], Q[j]);
        }
    }

};



int main(){
    

    Queue q;
    q.push(1 + 3);
    q.push(2 + 3);
    q.push(3 + 3);

    q.push(1);
    q.push(2);
    q.push(3);

    q.display();

    cout << (q.is_sorted() ? "sorted" : "not sorted") << "\n";
    q.sort();
    cout << (q.is_sorted() ? "sorted" : "not sorted") << "\n";


    return 0;
}