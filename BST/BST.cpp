#include <bits/stdc++.h>
using namespace std; 

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}


// indegree of root = 0
// outdegree of leaf = 0
// any subtree have a one root
// The leaf is not have a child
// The root is not have a parent
// the indegree in the tree <= 1

// Parent: any node that has children is a parent.
// Children: all the tree is children except the root.
// Leaves: all nodes that haven’t children.
// Internal nodes: nodes that have parents and children at the same time.
// external node is have a parent and not have a child
// Sibling: the children that have the same parent ⇾ level.
// Ancestor: the parent and grandparent of a node.
// Depth: it’s the number of edges from the root to the node.
// Height: it’s the number of edges from the node to the leaf in the maximum path.
// Edges: the number of edges = the number of nodes - 1.
// Out degree: the number of edges out from the node.
// In degree: the number of edges comes to it.
// Total degree: the sum of out degree and in degree.



class BST{

public:
 
  // Node is a class that have a data and left and right
  struct Node{
    int data;
    Node *left, *right;
    Node(int data){
      this -> data = data;
      left = right = nullptr;
    }
  };
  
  // root is a pointer to the root of the tree
  Node *root = nullptr;

  // insert function to insert a new node in the tree
  void insert(int data){
    root = insert(root, data);
  }

  Node *insert(Node *root, int data){
    if(!root) return new Node(data);
    if(data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
  }
  
  // size function to return the size of the tree
  int size(){
    return size(root);
  }

  int size(Node *root){
    if(!root) return 0; 
    return 1 + size(root->left) + size(root->right); 
  }  

  // inorder function to print the tree in inorder
  void inorder(){
    inorder(root);
    cout << "\n";
  }

  void inorder(Node *root){
     if (!root) return;
     inorder(root -> left);
     cout << root -> data << " ";
     inorder(root -> right); 
  } 

  // preorder function to print the tree in preorder
  void preorder(){
     preorder(root);
     cout << "\n";
  }

  void preorder(Node *root){
    if (!root) return;
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right); 
  }

  // postorder function to print the tree in postorder
  void postorder(){
    postorder(root);
    cout << "\n";
  }

  void postorder(Node *root){
    if (!root) return;
    postorder(root -> left);
    postorder(root -> right); 
    cout << root -> data << " ";
  }

  // search function to search for a node in the tree
  bool search(int data){
    return search(root, data);
  }

  bool search(Node *root, int num){
    if (!root) return false;
    if (root -> data < num) return search(root -> right, num);
    else if (root -> data > num) return search(root -> left, num);
    return true;
  }

  // minimam function to return the minimam value in the tree
  int minimam(){
    return minimam(root);
  }

  int minimam(Node *root){
    if (root -> left == nullptr) return root -> data;
    return minimam(root -> left);
  }

  // maximam function to return the maximam value in the tree
  int maximam(){
    return maximam(root);
  }

  int maximam(Node *root){
    if (root -> right == nullptr) return root -> data;
    return maximam(root -> right);
  }

  // remove function to remove a node from the tree
  void remove(int data){
    root = remove(root, data);
  }

  Node *remove(Node *root, int data){
    if (!root) return nullptr;
    if (root -> data < data) root -> right = remove(root -> right, data);
    else if (root -> data > data) root -> left = remove(root -> left, data);
    else{
      if (root -> left == nullptr){
        Node *temp = root -> right;
        delete root; 
        return temp;
      }
      else if (root -> right == nullptr) {
        Node *temp = root -> left;
        delete root;
        return temp;
      }
      else{
        int Min = minimam(root -> right);
        root -> data = Min;
        root -> right = remove(root -> right, Min);
      }
    }
    return root;
  }
    
    // depth function to return the depth of the tree
    int depth(){
        return depth(root);
    }

    int depth(Node *root){
        if(!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

  // destructor function to delete the tree
  ~BST(){
    delete root;
  }

};

int main()
{

  Gerges_Hany();

  BST tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);
  tree.inorder(); 
  tree.preorder(); 
  tree.postorder();
  tree.remove(5);
  tree.inorder(); 
  cout << tree.depth() << "\n";
  cout << tree.minimam() << " " << tree.maximam() << "\n";
  cout << (tree.search(5) ? "found" : "not found") << "\n";

  // 

  return 0;
}