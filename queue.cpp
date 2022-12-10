#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Queue{
    
    int *Q; // pointer to array of elements in the queue
    int Front, rear, size; 

    // constructor
    Queue(){
        Front = rear = -1; // initially the queue is empty
        size = 1e7; // the maximum size of the queue
        Q = new int[size]; // allocating the memory
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
            if(Q[i] == x) return i - 1;
        }
        return -1;
    }

    // insert an element at a specific index
    void insert(int index, int x){
        if(rear == size - 1)
            cout << "Queue is full" << "\n";
        else if (index < Front + 1 || index > rear + 1) // if the index is invalid
            cout << "Invalid index" << "\n";
        else{
            for (int i = rear; i >= index; i--) 
                Q[i + 1] = Q[i];
            Q[index] = x; rear++;
        }
    }

    // remove an element at a specific index
    void remove(int index){
        if(Front == rear)
            cout << "Queue is empty" << "\n";
        else if (index < Front + 1 || index > rear) // if the index is invalid
            cout << "Invalid index" << "\n";
        else{
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


    // enqueue N that will enqueue an array of N elements on the queue
    void enqueue_N(int N){
        for(int i = 0; i < N; i++){
            int x; cin >> x;
            push(x);
        }
    }

    // dequeue N that will dequeue and return an array of N elements from the queue
    int* dequeue_N(int N){
        // if N is negative return NULL
        if (N < 0) return NULL;
        // if the queue size is less than N return NULL
        if (N > sz()) return NULL;
        int F = Front;
        int *arr = new int[N];
        for(int i = 0; i < N; i++){
            arr[i] = Q[Front + 1];
            Front++;
        }
        Front = F;
        return arr;
    }


};


int main(){

    Queue q;
    for (int i = 1; i < 10; i++) q.push(i);
    //q.enqueue_N(5); 
    q.display();
    int N = 5;
    int *arr = q.dequeue_N(N);
        if (arr != NULL) 
            for (int i = 0; i < N; i++) 
            cout << arr[i] << " \n"[i == N - 1];
        else {
            cout << "NULL" << "\n";
            cout << (N < 0 ? "N is negative" : "N is greater than the queue size") << "\n";
        }


    cout << q.find_index(5) << "\n";
    cout << "The size equal " <<  q.sz() << "\n";
    
    q.display();
    q.reverse();
    q.display();

    cout << (q.is_sorted() ? "sorted" : "not sorted") << "\n";
    q.sort();
    q.display();
    cout << (q.is_sorted() ? "sorted" : "not sorted") << "\n";
    
    q.insert(3, 100);

    cout << "The minimum element in the queue equal " << q.find_min() << "\n";
    cout << "The maximum element in the queue equal " << q.find_max() << "\n";
    cout << "The sum of all elements in the queue equal " << q.get_sum() << "\n";

    return 0;
}
