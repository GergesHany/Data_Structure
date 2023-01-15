# What is Stack?


A Stack is a linear data structure that follows the LIFO (Last-In-First-Out) principle. Stack has one end, whereas the Queue has two ends (front and rear). It contains only one pointer top pointer pointing to the topmost element of the stack. Whenever an element is added in the stack, it is added on the top of the stack, and the element can be deleted only from the stack. In other words, a stack can be defined as a container in which insertion and deletion can be done from the one end known as the top of the stack.

## Some key points related to stack  

- It is called as stack because it behaves like a real-world stack, piles of books, etc.
- A Stack is an abstract data type with a pre-defined capacity, which means that it can store the elements of a limited size.
- It is a data structure that follows some order to insert and delete the elements, and that order can be LIFO or FILO.

![stack drawio2](https://user-images.githubusercontent.com/105644935/212522803-e0cf4437-f4bb-457c-b596-9085565b49a8.png)

## Working of Stack

Stack works on the LIFO pattern. As we can observe in the below figure there are five memory blocks in the stack; therefore, the size of the stack is 5.

Suppose we want to store the elements in a stack and let's assume that stack is empty. We have taken the stack of size 5 as shown below in which we are pushing the elements one by one until the stack becomes full.

![push stack](https://user-images.githubusercontent.com/105644935/212523006-6cbb2024-d33d-47bb-88ef-138c3eae1185.png)

Since our stack is full as the size of the stack is 5. In the above cases, we can observe that it goes from the top to the bottom when we were entering the new element in the stack. The stack gets filled up from the bottom to the top.

When we perform the delete operation on the stack, there is only one way for entry and exit as the other end is closed. It follows the LIFO pattern, which means that the value entered first will be removed last. In the above case, the value 5 is entered first, so it will be removed only after the deletion of all the other elements.

## PUSH operation
The steps involved in the PUSH operation is given below:

1. Before inserting an element in a stack, we check whether the stack is full.
2. If we try to insert the element in a stack, and the stack is full, then the overflow condition occurs.
3. When we initialize a stack, we set the value of top as -1 to check that the stack is empty.
4. When the new element is pushed in a stack, first, the value of the top gets incremented, i.e.
 top=top+1, and the element will be placed at the new position of the top.
5. The elements will be inserted until we reach the max size of the stack.

![push_stack](https://user-images.githubusercontent.com/105644935/212525899-1e290b34-9a9e-426d-9ef6-0ecc3b5c5d2c.gif)

## code
`implementation using the array`

```cpp
void push(int val){ 
    if (size == capacity){ // if the stack is full
      int *temp = new int[2 * capacity];  // double the capacity of the stack
      for (int i = 0; i < size; i++){ // copy the elements to the new array
        temp[i] = arr[i];
      }
      delete arr; // free the memory of the old array
      capacity *= 2; // double the capacity
      arr = temp; // point the arr to the new array
    }
    arr[size++] = val; // add the element to the top of the stack
  }
```

## POP operation
The steps involved in the POP operation is given below:
1. Before deleting the element from the stack, we check whether the stack is empty.
2. If we try to delete the element from the empty stack, then the underflow condition occurs.
3. If the stack is not empty, we first access the element which is pointed by the top
4. Once the pop operation is performed, the top is decremented by 1, i.e., top=top-1.

![pop-operation](https://user-images.githubusercontent.com/105644935/212526172-a203556c-ae13-4e51-8318-25e5b63c80b5.gif)

## code
`implementation using the array`

```cpp
void pop(){ 
  if (size == 0) { // if the stack is empty
      cout << "Stack is empty";
      return; 
  }
  size--; // decrease the size of the stack
}
```

## Applications of Stack
Following is the various Applications of Stack in Data Structure:
1. Evaluation of Arithmetic Expressions
2. Backtracking
3. Reverse a Data
4. Processing Function Calls

An example of an arithmetic expression

`Infix to Infix`

![applications-of-stack-in-data-structure2](https://user-images.githubusercontent.com/105644935/212526463-ac2f15d3-bb39-4848-8a12-2b74f95c5c4e.png)

## code

```cpp
string infix_to_postfix(string s){
    string ans; // the answer
    stack < char > st; // stack of char
    // priority function to get the priority of the operator
    auto priority = [](char c){
      if (c == '+' || c == '-') return 1;
      if (c == '*' || c == '/') return 2;
      return 0;
    };
    for (int i = 0; i < s.size(); i++){
      if (s[i] == '(') st.push(s[i]); // push the opening bracket
      else if (s[i] == ')'){ // if the current char is closing bracket
        while (st.top() != '('){ // pop all the operators until the opening bracket
          ans += st.top(); // add the operator to the answer
          st.pop(); // pop the operator from the stack
        }
        st.pop(); // pop the opening bracket
      }
      // if the current char is an operator
      else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
        // pop all the operators from the stack which has higher or equal priority
        while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(s[i])){
          ans += st.top(); // add the operator to the answer
          st.pop(); // pop the operator from the stack
        }
        st.push(s[i]); // push the current operator to the stack
      }
      else ans += s[i]; // if the current char is an operand, add it to the answer
    }
    // pop all the remaining operators from the stack
    while (!st.empty()){
      ans += st.top(); // add the operator to the answer
      st.pop(); // pop the operator from the stack
    }
    return ans; // return the answer
}  
```



