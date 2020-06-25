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
        TreeNode *successor, *t;
        successor = n->right;
        // Find the in-order successor of node n
        while(successor->left->left) {      // find left-most descendant
          successor = successor->left;
        }
        t = successor->left;                // t is now left-most descendant
        successor->left = t->right;         // t's parent takes on t's right sub-tree
        t->right = n->right;         // t replaces n
        if(n == root)
          root = t;
        else
          update_parent(parent, p_dir, t);
      }
    }
    delete n;
    size--;
    return true;

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
};

void test_1() {
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
}

void test_2() {
  BST b;

  b.insert(5);
  b.insert(12);
  b.insert(9);
  b.insert(21);
  b.insert(19);
  b.insert(25);

  std::cout << std::boolalpha << "remove 12: " << b.remove(12) << std::endl;
  std::cout << std::boolalpha << "contains 12? " << b.contains(12) << std::endl;
}

// http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html
void test_3() {
  BST b;

  b.insert(6);
  b.insert(2);
  b.insert(11);
  b.insert(1);
  b.insert(8);
  b.insert(15);
  b.insert(9);
  b.insert(10);

  std::cout << std::boolalpha << "remove 6: " << b.remove(6) << std::endl;
  std::cout << std::boolalpha << "contains 6? " << b.contains(6) << std::endl;
}

int main() {
  test_1();
  test_2();
  test_3();

  return 0;
}

// https://www.includehelp.com/data-structure-tutorial/deletion-in-binary-search-tree-bst.aspx

// Study-Links
// Hibbard Node Deletion algorithm
//  1. https://algs4.cs.princeton.edu/32bst/#:~:text=Hibbard%20in%201962%2C%20is%20to,are%20no%20keys%20between%20x.
//  2. http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html