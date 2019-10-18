#pragma once

#include <algorithm>

namespace trees {

template <typename value_t> class avl_tree {
  /**
   * @struct node struct defines behaviour of underlying elements in AVL-tree
   */
  struct node {
    node *left, *right;
    const value_t val;
    int count;
    int height;

    /**
     * C'tor. Initalizes node with value
     * @param value value for V-field
     */
    explicit node(const value_t &value)
        : val{value}, count{1}, height{1}, left{nullptr}, right{nullptr} {}

    /**
     * Re-calculcates values for successors after rotation
     */
    void update_values() {
      count = (left ? left->count : 0) + (right ? right->count : 0) + 1;

      height = std::max(left ? left->height : 0, right ? right->height : 0) + 1;
    }

    /**
     * Balance factor shows which of subtrees is bigger.
     * @return balance factor value for current node
     */
    int balance_factor() {
      return (left ? left->height : 0) - (right ? right->height : 0);
    }

    /**
     * Left-rotation after insert/delete operation
     * @return changed root for this subtree
     */
    node *left_rotate() {
      auto R = right;
      right = right->left;
      R->left = this;

      update_values();
      R->update_values();

      return R;
    }

    /**
     * Right-rotation after insert/delete operation
     * @return changed root for this subtree
     */
    node *right_rotate() {
      auto L = left;
      left = left->right;
      L->right = this;

      update_values();
      L->update_values();

      return L;
    }
  };

public:
  //  AVLTree() {}
  //  ~AVLTree() {}

private:
  std::size_t m_size;
  node *root;
};
}