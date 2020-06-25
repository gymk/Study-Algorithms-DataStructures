# Binary Search Tree

- BST is mainly used for maintaining and finding "Key Value" pair.
- The Key should be a comparable.

## Operations

Basic operations

    - Insert(key, data)
        - If key already exists, will update the new value
    - Remove(key)
        - Will remove the key-data pair if found
    - Contains(key)
        - Searches for existence of given key in BST and returns its status
    - min()
        - Returns value of the key pair having minimum key value
    - max
        - Returns value of the key pair having maximum key
    - GetSuccessor
        - Returns the successor of the given key (if passed)
    - GetPredecessor
        - Returns the predecessor of the given key (if passed)

Extended optional operations

    - Floor
    - Ceil
    - Rank
    - Select

## Traversal

### In-Order

- The values yielded in this traverse will be in ascending order (based on key)
- Sequence
  - Traverse Left
  - Process Node
  - Traverse Right

### Pre-Order

- Sequence
  - Process Node
  - Traverse Left
  - Traverse Right

### Post-Order

- Sequence
  - Traverse Left
  - Traverse Right
  - Process Node

## Balanced Binary Search Tree

TO DO

- AVL Tree
- Red Black Tree

## Study Links

- <https://www.includehelp.com/data-structure-tutorial/deletion-in-binary-search-tree-bst.aspx>
- <https://algs4.cs.princeton.edu/32bst/#:~:text=Hibbard%20in%201962%2C%20is%20to,are%20no%20keys%20between%20x>
- <http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/BST-delete2.html>
