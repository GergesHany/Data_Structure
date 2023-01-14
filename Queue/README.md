## What is Queue Data Structure?

A Queue is defined as a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order
![Queue-Data-Structures](https://user-images.githubusercontent.com/105644935/212500604-bdece733-5408-44da-ba2f-41dba816a9a3.png)


## FIFO Principle of Queue:

- A Queue is like a line waiting to purchase tickets, where the first person in line is the first person served. (i.e. First come first serve).
- Position of the entry in a queue ready to be served, that is, the first entry that will be removed from the queue, is called the front of the queue(sometimes, head of the queue), similarly, the position of the last entry in the queue, that is, the one most recently added, is called the rear (or the tail) of the queue. See the below figure.
- 
![fifo-property-in-Queue](https://user-images.githubusercontent.com/105644935/212500537-775b4fe9-ce1f-4260-bde6-c3f999c8b2a9.png)


## Characteristics of Queue:
- Queue can handle multiple data.
- We can access both ends.
- They are fast and flexible.  

## Queue Representation:
- Queue: the name of the array storing queue elements.
- Front: the index where the first element is stored in the array representing the queue.
- Rear: the index where the last element is stored in an array representing the queue.

<br>

# implementation of some functions

## push element at the end of the queue

![push](https://user-images.githubusercontent.com/105644935/212501024-557a99cc-f95e-4adc-93da-3397872c2379.gif)

## code

```cpp
void push(int x){
    if(rear == size - 1) // if the queue is full
      cout << "Queue is full" << "\n";
    else Q[++rear] = x; // increment the rear and add the element
}
```

## pop element from the front of the queue

![queue-delete-item](https://user-images.githubusercontent.com/105644935/212501144-14f1e388-9d80-4240-965b-01da6f474db4.gif)

## code

```cpp
void pop(){
    if(Front == rear) // if the queue is empty
        cout << "Queue is empty" << "\n"; 
     else Front++; // increment the front
}
```

<br>
<br>

`Illustrative image for the queue`

![maxresdefault](https://user-images.githubusercontent.com/105644935/212500514-b425958b-aa7f-4036-9954-e2c6a4f9e8b7.jpg)
