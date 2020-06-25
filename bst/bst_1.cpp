#include <iostream>

// Tree Node structure
struct TreeNode {
  int data;

  TreeNode * left;
  TreeNode * right;

  TreeNode(int d) {
    data = d;
    left = right = nullptr;
  }
};

// Binary Search Tree class
class BST {
private:
  TreeNode * root;
  int    size;

public:
  BST() {
    root = nullptr;
    size = 0;
  }
  ~BST() {
    delSubTree(root);
  }

  // recursively clears the given subtree at node n
  void delSubTree(TreeNode * n) {
    if(n != nullptr) {
      delSubTree(n->left);
      delSubTree(n->right);
      delete n;
    }
  }

  // searches for d in BST, returns true if found, otherwise returns false
  bool contains(int d) {
    TreeNode * n = root;
    bool found = false; // Only if BST doesn't contains d

    while( (n != nullptr) && !found) {
      // Have we found?
      if(n->data == d) {
        found = true;
      }
      // Do we need to traverse left
      else if(d < n->data) {
        n = n->left;
      }
      // We need to traverse right
      else {
        n = n->right;
      }
    }

    return found;
  }

  void insert(int d) {
    // Is this the first element in the BST?
    if(nullptr == root) {
      root = new TreeNode(d);
      size++;
      return;
    }

    TreeNode * n = root;

    // Traverse until either we need end of tree or until we find the note that we are trying to insert
    while((nullptr != n) && (n->data != d)) {
      if(d < n->data) {
        if(nullptr == n->left) {
          n->left = new TreeNode(d);
          size++;
          break;
        } else {
          n = n->left;
        }
      }
      else {
        if(nullptr == n->right) {
          n->right = new TreeNode(d);
          size++;
          break;
        } else {
          n = n->right;
        }
      }
    }
  }

  int min() {
    TreeNode * n = min(root);

    if(nullptr != n)
      return n->data;

    return 0;
  }

  int max() {
    TreeNode * n = max(root);

    if(nullptr != n)
      return n->data;

    return 0;
  }

  // Uses Hibbard BST delete algorithm
  bool remove(int d) {
    if (!root) {
      return false;
    }

    TreeNode * n = root;
    TreeNode * parent = nullptr; // track the target node's parent so we can update its left or right tree
    int p_dir = 0;               // parent direction - 1: left, 2: right

    // Traverse until either we read end-of-tree or until we find the node
    while((n != nullptr) && (n->data != d)) {
      if(d < n->data) {
        parent = n;
        p_dir = 1;
        n = n->left;
      } else {
        parent = n;
        p_dir = 2;
        n = n->right;
      }
    }

    // This BST doesn't have the requested d
    if(nullptr == n) {
      return false;
    }

    if(!n->left && !n->right) {     // 1. Node n is a leaf node
      update_parent(parent, p_dir, nullptr);
    }
    else if(!n->left && n->right) { // 2 (a). Node n has only a right child
      if(n == root)
        root = n->right;
      else
        update_parent(parent, p_dir, n->right);
    }
    else if(n->left && !n->right) { // 2 (b). Node n has only left child
      if(n == root)
        root = n->left;
      else
        update_parent(parent, p_dir, n->left);
    }
    else {
      if(!n->right->left) {         // 3 (a). Right child has no left child
        n->right->left = n->left;
        if(n == root)
          root = n->right;
        else
          update_parent(parent, p_dir, n->right);
      }
      else {                        // 3 (b). Right child has left child
        TreeNode *successor, *tmp;
        successor = n->right;
        // Find the in-order successor of node n
        // Particularly parent of the successor
        while(successor->left->left) {      // find left-most descendant
          successor = successor->left;
        }
        tmp = successor->left;              // tmp is now left-most descendant
        successor->left = tmp->right;       // tmp's parent takes on tmp's right sub-tree
        tmp->right = n->right;              // tmp replaces n
        if(n == root)
          root = tmp;
        else
          update_parent(parent, p_dir, tmp);
      }
    }
    delete n;
    size--;
    return true;

  }

  void inorder_traverse(void) {
    std::cout << "In-Order Traverse: ";
    inorder(root);
    std::cout << std::endl;
  }

  void preorder_traverse(void) {
    std::cout << "Pre-Order Traverse: ";
    preorder(root);
    std::cout << std::endl;
  }

  void postorder_traverse(void) {
    std::cout << "Post-Order Traverse: ";
    postorder(root);
    std::cout << std::endl;
  }

private:
  TreeNode * min(TreeNode * n) {
    if(nullptr == n)
      return nullptr;

    while(n->left != nullptr)
      n = n->left;

    return n;
  }

  TreeNode * max(TreeNode * n) {
    if(nullptr == n)
      return nullptr;
    
    while(n->right != nullptr)
      n = n->right;

    return n;
  }

  void update_parent(TreeNode * n, int p_dir, TreeNode * child_node) {
    if(nullptr != n) {
      if(p_dir == 1) {
        n->left = child_node;
      } else {
        n->right = child_node;
      }
    }
  }

  void inorder(TreeNode * n) {
    if(nullptr == n)
      return;

    inorder(n->left);
    std::cout << n->data << " ";
    inorder(n->right);
  }

  void preorder(TreeNode * n) {
    if(nullptr == n)
      return;
    std::cout << n->data << " ";
    postorder(n->left);
    postorder(n->right);
  }

  void postorder(TreeNode * n) {
    if(nullptr == n)
      return;

    preorder(n->left);
    preorder(n->right);
    std::cout << n->data << " ";
  }
};

void test_1() {
  std::cout << "Test Case 1" << std::endl;

  BST b;

  b.insert(90);
  b.insert(50);
  b.insert(150);
  b.insert(150);
  b.insert(20);
  b.insert(75);
  b.insert(66);
  b.insert(80);
  b.insert(60);
  b.insert(68);
  b.insert(62);
  b.insert(10);

  b.inorder_traverse();
  b.preorder_traverse();
  b.postorder_traverse();

  // min & max
  std::cout << "min: " << b.min() << ", max: " << b.max() << std::endl;

  // Search
  // std::cout << std::boolalpha << "contains 60? " << b.contains(60) << std::endl;

  // Delete - Leaf
  std::cout << std::boolalpha << "remove 150: " << b.remove(150) << std::endl;
  std::cout << std::boolalpha << "contains 150? " << b.contains(150) << std::endl;

  // Delete - No right child (similar for No left child case)
  // std::cout << std::boolalpha << "remove 20: " << b.remove(20) << std::endl;
  // std::cout << std::boolalpha << "contains 20? " << b.contains(20) << std::endl;

  // Delete - root node
  // std::cout << std::boolalpha << "remove 90: " << b.remove(90) << std::endl;
  // std::cout << std::boolalpha << "contains 90? " << b.contains(90) << std::endl;

  // Delete-
  // std::cout << std::boolalpha << "remove 50: " << b.remove(50) << std::endl;
  // std::cout << std::boolalpha << "contains 50? " << b.contains(50) << std::endl;

  std::cout << std::endl;
}

void test_2() {
  std::cout << "Test Case 2" << std::endl;

  BST b;

  b.insert(5);
  b.insert(12);
  b.insert(9);
  b.insert(21);
  b.insert(19);
  b.insert(25);

  b.inorder_traverse();
  b.preorder_traverse();
  b.postorder_traverse();

  // min & max
  std::cout << "min: " << b.min() << ", max: " << b.max() << std::endl;

  std::cout << std::boolalpha << "remove 12: " << b.remove(12) << std::endl;
  std::cout << std::boolalpha << "contains 12? " << b.contains(12) << std::endl;

  std::cout << std::endl;
}

// http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html
void test_3() {
  std::cout << "Test Case 3" << std::endl;

  BST b;

  b.insert(6);
  b.insert(2);
  b.insert(11);
  b.insert(1);
  b.insert(8);
  b.insert(15);
  b.insert(9);
  b.insert(10);

  b.inorder_traverse();
  b.preorder_traverse();
  b.postorder_traverse();

  // min & max
  std::cout << "min: " << b.min() << ", max: " << b.max() << std::endl;

  std::cout << std::boolalpha << "remove 6: " << b.remove(6) << std::endl;
  std::cout << std::boolalpha << "contains 6? " << b.contains(6) << std::endl;

  std::cout << std::endl;
}

// https://algs4.cs.princeton.edu/32bst/
void test_4() {
  std::cout << "Test Case 4" << std::endl;

  BST b;

  b.insert('S');
  b.insert('E');
  b.insert('X');
  b.insert('A');
  b.insert('R');
  b.insert('C');
  b.insert('H');
  b.insert('M');
  b.insert('G');

  b.inorder_traverse();
  b.preorder_traverse();
  b.postorder_traverse();

  // min & max
  std::cout << "min: " << b.min() << ", max: " << b.max() << std::endl;

  std::cout << std::boolalpha << "remove 6: " << b.remove(6) << std::endl;
  std::cout << std::boolalpha << "contains 6? " << b.contains(6) << std::endl;

  std::cout << std::endl;
}

int main() {
  test_1();
  test_2();
  test_3();
  test_4();

  return 0;
}

// https://www.includehelp.com/data-structure-tutorial/deletion-in-binary-search-tree-bst.aspx

// Study-Links
// Hibbard Node Deletion algorithm
//  1. https://algs4.cs.princeton.edu/32bst/#:~:text=Hibbard%20in%201962%2C%20is%20to,are%20no%20keys%20between%20x.
//  2. http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html

/*
Output:

Test Case 1
In-Order Traverse: 10 20 50 60 62 66 68 75 80 90 150
Pre-Order Traverse: 90 20 10 75 60 62 68 66 80 50 150
Post-Order Traverse: 50 10 20 66 62 60 68 80 75 150 90
min: 10, max: 150
remove 150: true
contains 150? false

Test Case 2
In-Order Traverse: 5 9 12 19 21 25
Pre-Order Traverse: 5 9 21 19 25 12
Post-Order Traverse: 12 9 19 25 21 5
min: 5, max: 25
remove 12: true
contains 12? false

Test Case 3
In-Order Traverse: 1 2 6 8 9 10 11 15
Pre-Order Traverse: 6 1 2 8 10 9 15 11
Post-Order Traverse: 2 1 11 9 10 8 15 6
min: 1, max: 15
remove 6: true
contains 6? false

Test Case 4
In-Order Traverse: 65 67 69 71 72 77 82 83 88 
Pre-Order Traverse: 83 65 67 82 71 77 72 69 88
Post-Order Traverse: 69 67 65 72 71 77 82 88 83
min: 65, max: 88
remove 6: false
contains 6? false
*/