**Arrays Vs Linked Lists**


The following are some of the differences between Arrays and Linked Lists:

| Arrays  | Linked Lists |
| :----: | :----: |
| An array is a collection of elements of a similar data type.   | 	Linked List is an ordered collection of elements of the same type in which each element is connected to the next using pointers.  |
| Array elements can be accessed randomly using the array index.  | 	Random accessing is not possible in linked lists. The elements will have to be accessed sequentially  |
| Data elements are stored in contiguous locations in memory.  | New elements can be stored anywhere and a reference is created for the new element using pointers.  |
| Insertion and Deletion operations are costlier since the memory locations are consecutive and fixed.    | Insertion and Deletion operations are fast and easy in a linked list. |
| Memory is allocated during the compile time (Static memory allocation).|  Memory is allocated during the run-time (Dynamic memory allocation).    |  
| Size of the array must be specified at the time of array declaration/initialization.   |  	Size of a Linked list grows/shrinks as and when new elements are inserted/deleted.    |  

<br>

**Advantages of Linked Lists**
1. Size of linked lists is not fixed, they can expand and shrink during run time.
2. Insertion and Deletion Operations are fast and easier in Linked Lists.
3. Memory allocation is done during run-time (no need to allocate any fixed memory).
4. Data Structures like Stacks, Queues, and trees can be easily implemented using Linked list.  

<br>

**Disadvantages of Linked Lists**

1. Memory consumption is more in Linked Lists when compared to arrays  
  Because each node contains a pointer in linked list and it requires extra memory.
2. Elements cannot be accessed at random in linked lists.
3. Traversing from reverse is not possible in singly linked lists.

<br>

**Applications of Linked Lists**

1. Linked Lists can be used to implement Stacks, Queues and Trees.
2. Linked Lists can be also used to implement Graphs. (Adjacency list representation of Graph).
3. Linked Lists can be used to Implement Hash Tables - Each Bucket of the hash table can be a linked list (Open chain hashing).

