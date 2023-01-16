What is Binary Search Tree?  

Binary Search Tree is a node-based binary tree data structure which has the following properties:

1. The left subtree of a node contains only nodes with keys lesser than the node’s key.  
2. The right subtree of a node contains only nodes with keys greater than the node’s key. 
3. The left and right subtree each must also be a binary search tree.  
4. This means everything to the left of the root is less than the value of the root and everything to the right of the root is greater than the value of the root. Due to this performing, a binary search is very easy.
5. The left and right subtree each must also be a binary search tree.  
There must be no duplicate nodes(BST may have duplicate values with different handling approaches)


## Delete node is binary search tree
- the node not have any child (delete it)
- the node have one child (delete it and replace it with its child)
- the node have two child (replace it with the (minimum value in the right subtree or maximam value in the left subtree)) 

## find the successor of the node
- the node have right child (the minimum value in the right subtree)
- the node not have right child (the parent of the node)
- the node not have right child and it is the left child of its parent (the parent of the node)

## find the predecessor of the node
- the node have left child (the maximum value in the left subtree)
- the node not have left child (the parent of the node) 
- the node not have left child and it is the right child of its parent (the parent of the node)

<br>

## binary search tree:

![optimal-binary-search-tree-from-sorted-array](https://user-images.githubusercontent.com/105644935/212498710-9be49e0e-ea92-4176-ac9b-7c866b85a8cb.gif)


#### The number "21" is a root is the parent of all nodes
#### The root is not have a parent (root is the parent of all nodes)
#### Internal nodes: nodes that have parents and children at the same time for ex (11, 18, 25, 32)
#### Sibling: the children that have the same parent and the same level for ex ({5, 12}, {15, 19}, {23, 27}, {30, 37}) 
#### Ancestor: the parent and grandparent of a node for ex the Ancestor for 5 is (11, 14, 25)
#### leaf: is have a parent and not have a child for ex (5, 12, 15, 19, 23, 27, 30, 37)
#### Depth: it’s the number of edges from the root to the node 
#### Height: it’s the number of edges from the node to the leaf in the maximum path.
#### node: is the point in the tree for ex (21, 14, 18, 11, 5, 12, 15, 19, 28, 25, 32, 23, 27, 30, 37)
#### Edges: is the connection between two nodes "and" the number of edges = the number of nodes - 1.


### print the tree in inorder

![binary-tree-1-order](https://user-images.githubusercontent.com/105644935/212496125-bb713c95-ff64-4173-b57d-03ae3973e742.gif)

## code

```cpp
void inorder(Node *root){
   if (!root) return; // if the root is null return
   inorder(root -> left); // go to the left child of the root
   cout << root -> data << " "; // print the data of the root
   inorder(root -> right);  // go to the right child of the root
 }
```
### print the tree in preorder
![binary-tree-1-pre-order](https://user-images.githubusercontent.com/105644935/212496397-83373151-8442-4c49-9d4e-053112f20254.gif)

## code

```cpp
void preorder(Node *root){
  if (!root) return; // if the root is null return
  cout << root -> data << " "; // print the data of the root
  preorder(root -> left); // go to the left child of the root
  preorder(root -> right);  // go to the right child of the root
 }
```

### print the tree in postorder
![binary-tree-1-post-order](https://user-images.githubusercontent.com/105644935/212496500-269d81ce-e07b-480b-81d2-46cb7ef143b5.gif)


## code

```cpp
void postorder(Node *root){
  if (!root) return; // if the root is null return
  postorder(root -> left); // go to the left child of the root
  postorder(root -> right);  // go to the right child of the root
  cout << root -> data << " "; // print the data of the root
}
```
### insert a new node in the tree

![BST-insertion-animation](https://user-images.githubusercontent.com/105644935/212496783-23b465aa-8d26-41e7-ad77-606ddc5c9ce6.gif)

## code

```cpp
  Node *insert(Node *root, int data){
    if(!root) return new Node(data); // if the root is null return a new node with the data
    if(data < root->data) root->left = insert(root->left, data); // if the data is less than the data of the root go to the left child of the root
    else root->right = insert(root->right, data); // if the data is greater than the data of the root go to the right child of the root
    return root; // return the root
  }
```

### remove a node from the tree

![delete_bst](https://user-images.githubusercontent.com/105644935/212497030-df8d8105-dfa1-4763-832f-a3173a48a003.gif)


## code

```cpp

  Node *remove(Node *root, int data){
    if (!root) return nullptr; // if the root is null return null
    // if the data is less than the data of the root go to the left child of the root
    if (root -> data < data) root -> right = remove(root -> right, data); 
    // if the data is greater than the data of the root go to the right child of the root
    else if (root -> data > data) root -> left = remove(root -> left, data);
    // if the data is equal to the data of the root
    else{
      // if the root have two children
      if (root -> left == nullptr){
        // if the root have a right child
        Node *temp = root -> right; // make a pointer to the right child of the root
        delete root;  // delete the root
        return temp; // return the pointer to the right child of the root
      }
      // if the root have a left child
      else if (root -> right == nullptr) {
        Node *temp = root -> left; // make a pointer to the left child of the root
        delete root; // delete the root
        return temp; // return the pointer to the left child of the root
      }
      // if the root have two children
      else{ 
        // find the minimam value in the right subtree of the root
        int Min = minimam(root -> right); 
        root -> data = Min; // make the data of the root equal to the minimam value in the right subtree of the root
        root -> right = remove(root -> right, Min); // remove the minimam value in the right subtree of the root
      }
    }
    return root; // return the root
  }
```

### the depth of the tree

![1_hrZ0yydmke-BJ7QCcdwfAw](https://user-images.githubusercontent.com/105644935/212498589-936f8d43-baf3-4cee-b137-bee472b05587.gif)


## code

```cpp
int depth(Node *root){
    if(!root) return 0; // if the root is null return 0
    // return 1 + the maximum between the depth of the left child of the root and the depth of the right child of the root
    return 1 + max(depth(root->left), depth(root->right));
 }
```







