# AVL Tree

## Description

AVL-Tree is a **self-balancing** BST which guarantees `O(log(n))` time complexity for insert, delete and look-up operations.

This version allows duplicates, so it means the tree can be used as `std::multiset` which based on Red-Black tree.

## How to use

This project is header-only and can be used just with `#include <avl_tree.hpp>` preprocessor directive.

To run unit-tests you can compile it by yourself with `cmake`

## Performance test vs `std::multiset`

As we know that `std::multiset` in standard template library (STL) is based on Red Black Trees (**RB Trees**) and both RB Trees and AVL Trees support insertion, deletion and look-up in guaranteed O(logN) time. However,
 AVL Trees are more rigidly balanced, it means that AVL Trees need more rotations in insertion and deletion, but provide faster look-up. So you are strongly recommended to use AVL Trees for **look-up** intensive tasks,
  otherwise RB Trees (also `std::multiset`) are more convenient. 
  
  | Task | Amount | Container | Time Elapsed (ms) |
  | --- | :--- | :---: | :---: |
  | `insertion` | 100.000 | AVL Tree<br>`std::multiset `| 150<br>**19** |
  | `insertion` | 1.000.000 | AVL Tree<br>`std::multiset` | 1596<br>**230** |
  | `deletion` | 100.000 | AVL Tree<br>`std::multiset` | 122<br>**16** |
  | `deletion` | 1.000.000 | AVL Tree<br>`std::multiset` | 1214<br>**145** |
  | `look-up` | 100.000 | AVL Tree<br>`std::multiset` | 6<br>**4**  |
  | `look-up` | 1.000.000 | AVL Tree<br>`std::multiset` | 70<br>**60** |
  | `look-up` | 10.000.000 | AVL Tree<br>`std::multiset` | **398**<br>1554 |
  | `look-up` | 100.000.000 | AVL Tree<br>`std::multiset` | **3536**<br>19238 |
  
  > In look-up and deletion operations, containers have 100.000 elements.